import java.awt.*;
import java.awt.event.*;

import javax.swing.*;


public class backend extends JComponent
{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	static int X_TRANS = 0;
    static int Y_TRANS = 1;
    static int Z_TRANS = 2;
    static int X_SCALE = 3;
    static int Y_SCALE = 4;
    static int Z_SCALE = 5;
    static int X_ROT = 6;
    static int Y_ROT = 7;
    static int Z_ROT = 8;
    static int PERSPECTIVE = 9;
    
    static double MinxView;
    static double MinyView;
    static double MaxxView;
    static double MaxyView;

    static int frameWidth = 700;
    static int frameHeight = 700;

    static double x; //universal use coords
    static double y;
    static double z;

    public static void InitGraphics()
    {
	JFrame f = new JFrame("assign4");
	
	f.addWindowListener(new WindowAdapter()
	{
	    public void windowClosing(WindowEvent e)
	    {
		System.exit(0);
	    }
	}
	);
	
	f.setSize(frameWidth, frameHeight);
	f.getContentPane().add(new assign4());
	f.setVisible(true);
	DefineViewport(-1, -1, 1, 1);
    
    }

    public static void DefineViewport(double minx, double miny, double maxx, double maxy)
    {

	MinxView = minx;
	MinyView = miny;
	MaxxView = maxx;
	MaxyView = maxy;
    }

    public static window DefineWindow(double width1, double height1, double width2, double height2, 
    		double vpxMin, double vpyMin, double vpxMax, double vpyMax)
    {
    	 
	window w1 = new window();
	w1.winMinX = width1;
	w1.winMinY = height1;
	w1.winMaxX = width2;
	w1.winMaxY = height2;
	w1.vpxMin = vpxMin;
	w1.vpyMin = vpyMin;
	w1.vpxMax = vpxMax;
	w1.vpyMax = vpyMax;

	return w1;
    }

	public static point ViewportToWindow(window w1, point p)
    {
		
     if (p.x > w1.vpxMax) 
      p.x = w1.vpxMax;
     if (p.x < w1.vpxMin) 
      p.x = w1.vpxMin;
     if (p.y > w1.vpyMax) 
      p.y = w1.vpyMax;
     if (p.y < w1.vpyMin) 
      p.y = w1.vpyMin;
     point p2 = new point();
     p2.x = frameWidth * ((p.x - MinxView) / (MaxxView - MinxView));
     p2.y = frameHeight * ((-(p.y) - MinyView) / (MaxyView - MinyView));
	   
     return p2;
    }

    
    public static point WindowToViewport(window w1, double xwin, double ywin)
    {
    if (xwin > w1.winMaxX) 
	 xwin = w1.winMaxX;
	if (xwin < w1.winMinX) 
	 xwin = w1.winMinX;
	if (ywin > w1.winMaxY) 
	 ywin = w1.winMaxX;
	if (ywin < w1.winMinY) 
	 ywin = w1.winMaxY;
	
	point p = new point();
	p.x = ((( xwin - w1.winMinX ) / ( w1.winMaxX - w1.winMinX )) * (w1.vpxMax - w1.vpxMin)) + w1.vpxMin;	
	p.y = ((( ywin - w1.winMinY ) / ( w1.winMaxY - w1.winMinY )) * (w1.vpyMax - w1.vpyMin)) + w1.vpyMin;
	return p;
    }

    public static void Move3D(window w1, point p, matrix transM, matrix cameraTrans)
    {
      p = ApplyTransform(p, transM);
      p = ApplyTransform(p, cameraTrans);

      p = WindowToViewport(w1, p.x, p.y);
      MoveTo(p);
    }

    public static void Draw3D(window w1, point p, matrix transM, matrix cameraTrans, Graphics g)
    {

      p = ApplyTransform(p, transM);
      p = ApplyTransform(p, cameraTrans);


      p = WindowToViewport(w1, p.x, p.y);

      DrawTo(p, g);
    }

    public static point ApplyTransform(point p, matrix transM)
    {
     double pvector[] = new double[4];
     pvector[0] = p.x;
     pvector[1] = p.y;
     pvector[2] = p.z;
     pvector[3] = 1;

     for( int i = 0; i < 4; i++ )
      for( int j = 0; j < 4; j++ )
       pvector[i] += pvector[j]*transM.matrix[j][i];

     p.x = pvector[0]/pvector[3];
     p.y = pvector[1]/pvector[3];
     p.z = pvector[2]/pvector[3];     
     return p;
    }


    public static void MoveTo(point p)
    {
	x = p.x;
	y = p.y;
    }

    public static void DrawTo(point p, Graphics g)
    {
    int x1 = (int)(x * 100);
	int x2 = (int)(p.x * 100);
	int y1 = (int)(y * 100);
	int y2 = (int)(p.y * 100);
	g.drawLine(x1, y1, x2, y2);

	MoveTo(p);
    }


    public static matrix BuildET(matrix transM, int transCode, double transVal)
    {
      matrix temp1 = new matrix();
      matrix temp2 = new matrix();

      temp1 = DefineET(temp1, transCode, transVal);

      if (transCode <= 2)  //if it's a translate, we only need to add
       {
        for( int j = 0; j < 4; j++ )
         for( int i = 0; i < 4; i++ )
	  transM.matrix[j][i] += temp2.matrix[j][i];
       }
      else  //otherwise other actions
       {
        temp2 = matrix.MultiplyM(transVal, temp1, temp2);
      
         for( int j = 0; j < 4; j++ )
          for( int i = 0; i < 4; i++ )
	   transM.matrix[j][i] = temp2.matrix[j][i];
       }

      return transM;
     }


    public static matrix DefineET(matrix transM, int transCode, double transVal)
    {
      matrix m = new matrix();

      if (transCode == 0)
      {      
        m.SetMVal(0,0,transVal);
	m.SetMVal(0,1,0);
	m.SetMVal(0,2,0);
	m.SetMVal(0,3,0);
	m.SetMVal(1,0,0);
	m.SetMVal(1,1,0);
	m.SetMVal(1,2,0);
	m.SetMVal(1,3,0);
	m.SetMVal(2,0,0);
	m.SetMVal(2,1,0);
	m.SetMVal(2,2,0);
	m.SetMVal(2,3,0);
	m.SetMVal(3,0,0);
	m.SetMVal(3,1,0);
	m.SetMVal(3,2,0);
	m.SetMVal(3,3,1);
       }
      else if (transCode == 1)
      {      
        m.SetMVal(0,0,0);
	m.SetMVal(0,1,0);
	m.SetMVal(0,2,0);
	m.SetMVal(0,3,0);
	m.SetMVal(1,0,0);
	m.SetMVal(1,1,transVal);
	m.SetMVal(1,2,0);
	m.SetMVal(1,3,0);
	m.SetMVal(2,0,0);
	m.SetMVal(2,1,0);
	m.SetMVal(2,2,0);
	m.SetMVal(2,3,0);
	m.SetMVal(3,0,0);
	m.SetMVal(3,1,0);
	m.SetMVal(3,2,0);
	m.SetMVal(3,3,1);
       }
      else if (transCode == 2)
      {      
        m.SetMVal(0,0,0);
	m.SetMVal(0,1,0);
	m.SetMVal(0,2,0);
	m.SetMVal(0,3,0);
	m.SetMVal(1,0,0);
	m.SetMVal(1,1,0);
	m.SetMVal(1,2,0);
	m.SetMVal(1,3,0);
	m.SetMVal(2,0,0);
	m.SetMVal(2,1,0);
	m.SetMVal(2,2,transVal);
	m.SetMVal(2,3,0);
	m.SetMVal(3,0,0);
	m.SetMVal(3,1,0);
	m.SetMVal(3,2,0);
	m.SetMVal(3,3,1);
       }
      else if (transCode == 3)
      {      
        m.SetMVal(0,0,transVal);
	m.SetMVal(0,1,0);
	m.SetMVal(0,2,0);
	m.SetMVal(0,3,0);
	m.SetMVal(1,0,0);
	m.SetMVal(1,1,0);
	m.SetMVal(1,2,0);
	m.SetMVal(1,3,0);
	m.SetMVal(2,0,0);
	m.SetMVal(2,1,0);
	m.SetMVal(2,2,0);
	m.SetMVal(2,3,0);
	m.SetMVal(3,0,0);
	m.SetMVal(3,1,0);
	m.SetMVal(3,2,0);
	m.SetMVal(3,3,1);
       }
      else if (transCode == 4)
      {      
        m.SetMVal(0,0,0);
	m.SetMVal(0,1,0);
	m.SetMVal(0,2,0);
	m.SetMVal(0,3,0);
	m.SetMVal(1,0,0);
	m.SetMVal(1,1,transVal);
	m.SetMVal(1,2,0);
	m.SetMVal(1,3,0);
	m.SetMVal(2,0,0);
	m.SetMVal(2,1,0);
	m.SetMVal(2,2,0);
	m.SetMVal(2,3,0);
	m.SetMVal(3,0,0);
	m.SetMVal(3,1,0);
	m.SetMVal(3,2,0);
	m.SetMVal(3,3,1);
       }
      else if (transCode == 5)
      {      
        m.SetMVal(0,0,0);
	m.SetMVal(0,1,0);
	m.SetMVal(0,2,0);
	m.SetMVal(0,3,0);
	m.SetMVal(1,0,0);
	m.SetMVal(1,1,0);
	m.SetMVal(1,2,0);
	m.SetMVal(1,3,0);
	m.SetMVal(2,0,0);
	m.SetMVal(2,1,0);
	m.SetMVal(2,2,transVal);
	m.SetMVal(2,3,0);
	m.SetMVal(3,0,0);
	m.SetMVal(3,1,0);
	m.SetMVal(3,2,0);
	m.SetMVal(3,3,1);
       }
      else if (transCode == 6)
      {      
        m.SetMVal(0,0,1);
	m.SetMVal(0,1,0);
	m.SetMVal(0,2,0);
	m.SetMVal(0,3,0);
	m.SetMVal(1,0,0);
	m.SetMVal(1,1,Math.cos(transVal));
	m.SetMVal(1,2,Math.sin(transVal));
	m.SetMVal(1,3,0);
	m.SetMVal(2,0,0);
	m.SetMVal(2,1,-(Math.sin(transVal)));
	m.SetMVal(2,2,Math.cos(transVal));
	m.SetMVal(2,3,0);
	m.SetMVal(3,0,0);
	m.SetMVal(3,1,0);
	m.SetMVal(3,2,0);
	m.SetMVal(3,3,1);
       }
      else if (transCode == 7)
      {      
        m.SetMVal(0,0,Math.cos(transVal));
	m.SetMVal(0,1,0);
	m.SetMVal(0,2,Math.sin(transVal));
	m.SetMVal(0,3,0);
	m.SetMVal(1,0,0);
	m.SetMVal(1,1,1);
	m.SetMVal(1,2,0);
	m.SetMVal(1,3,0);
	m.SetMVal(2,0,-(Math.sin(transVal)));
	m.SetMVal(2,1,0);
	m.SetMVal(2,2,Math.cos(transVal));
	m.SetMVal(2,3,0);
	m.SetMVal(3,0,0);
	m.SetMVal(3,1,0);
	m.SetMVal(3,2,0);
	m.SetMVal(3,3,1);
       }
      else if (transCode == 8)
      {      
        m.SetMVal(0,0,Math.cos(transVal));
	m.SetMVal(0,1,Math.sin(transVal));
	m.SetMVal(0,2,0);
	m.SetMVal(0,3,0);
	m.SetMVal(1,0,-(Math.sin(transVal)));
	m.SetMVal(1,1,Math.cos(transVal));
	m.SetMVal(1,2,0);
	m.SetMVal(1,3,0);
	m.SetMVal(2,0,0);
	m.SetMVal(2,1,0);
	m.SetMVal(2,2,1);
	m.SetMVal(2,3,0);
	m.SetMVal(3,0,0);
	m.SetMVal(3,1,0);
	m.SetMVal(3,2,0);
	m.SetMVal(3,3,1);
       }
      else if (transCode == 9)
      {      
        m.SetMVal(0,0,1);
	m.SetMVal(0,1,0);
	m.SetMVal(0,2,0);
	m.SetMVal(0,3,0);
	m.SetMVal(1,0,0);
	m.SetMVal(1,1,1);
	m.SetMVal(1,2,0);
	m.SetMVal(1,3,0);
	m.SetMVal(2,0,0);
	m.SetMVal(2,1,0);
	m.SetMVal(2,2,1);
	m.SetMVal(2,3,-(1/transVal));
	m.SetMVal(3,0,0);
	m.SetMVal(3,1,0);
	m.SetMVal(3,2,0);
	m.SetMVal(3,3,1);
       }
      return m;
    }

    public static matrix DefineCT(double focalx, double focaly, double focalz, double theta, double phi, double alpha, double distance)
    {
     matrix CAMERA = new matrix();
     CAMERA = DefineET(CAMERA, X_TRANS, -focalx);
     CAMERA = BuildET(CAMERA, Y_TRANS, -focaly);
     CAMERA = BuildET(CAMERA, Z_TRANS, -focalz);

     CAMERA = BuildET(CAMERA, Y_ROT, -theta);
     CAMERA = BuildET(CAMERA, X_ROT, phi);
     CAMERA = BuildET(CAMERA, Z_ROT, -alpha);

     CAMERA = BuildET(CAMERA, PERSPECTIVE, distance);
     
     return CAMERA;
    }
 
   

}
