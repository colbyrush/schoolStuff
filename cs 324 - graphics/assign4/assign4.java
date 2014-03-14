/* CS 324.Bolden.........Javac SE 7u51...........Colby Rush
 * 3/14/2014 ............ .............cooby.rush@gmail.com
 *
 * Basic 3D images
 *----------------------------------------------------------
 */

import java.awt.Graphics;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JComponent;
import javax.swing.JFrame;


public class assign4 extends JComponent
{
	
	static int X_TRANS = 0; //macros for defineET
    static int Y_TRANS = 1;
    static int Z_TRANS = 2;
    static int X_SCALE = 3;
    static int Y_SCALE = 4;
    static int Z_SCALE = 5;
    static int X_ROT = 6;
    static int Y_ROT = 7;
    static int Z_ROT = 8;
    static int PERSPECTIVE = 9;
    
    public static JFrame f; //easier way to check window size, etc.

    double x; //universal use coords
    double y;
    double z;
    
    public static window w;
    public static viewport v;
    
    public static void main( String[] args)
    {
    	assign4 begin = new assign4(); //time to go!
    	begin.InitGraphics();
    }


    public void InitGraphics()
    {  	
    	v = new viewport(0,0,1,1);
        w = new window(-10,-10,10,10);
        
	f = new JFrame("assign4");
	
	f.addWindowListener(new WindowAdapter()
	{
	    public void windowClosing(WindowEvent e)
	    {
		System.exit(0);
	    }
	}
	);
	

	f.setSize(700, 700);
	f.setLocation(400, 0);
	
	f.getContentPane().add(new assign4());
	f.setVisible(true);
    
    }

    public void paintComponent( Graphics g) //actual creation
    {	

	// Create first window
        v.DefineViewport(0, 0, 1, 1);
        w.DefineWindow(-100, -100, 100, 100); //arbitrary testing numbers
    
        //axes
        g.drawLine(f.getWidth() / 2, 0, f.getWidth() / 2, f.getHeight());
        g.drawLine(0, f.getHeight() / 2, f.getWidth(), f.getHeight() / 2);
        
        matrix graphM = DefineET(X_TRANS, 0);
        matrix CAMERA = new matrix();
        
        double zp = 0;
        
        //lower bounds to start at
        vector v = new vector(-1.25,-1.25,23.24,1); //lower bound for equation
        
        vector v2 = new vector(0,0,0,1);
        for (x = -1.25; x <= 1.25; x+=.01)
        	{
        	MoveTo(v); //reset to start to account for 3D directions
        	for (y = -1.25; y <= 1.25 ; y+=0.1)
        	{
        		zp = (Math.pow(x,2) + Math.pow(y,2) - Math.pow(x,3) - (8 * (x) * (Math.pow(y, 4)))); //solve for z
        		v.SetVector(x,y,zp,1);
                CAMERA = DefineCT(v2, 90, 90, 0, 5);
        		Draw3D(v,graphM,CAMERA,g); //draw it
        	}
        	}
        
        
        point nameP = new point();
        nameP.x = (f.getWidth() / 2);
        nameP.y = (f.getHeight() / 2);
        PrintName(nameP, g);
    }
  //tools start here
    
    
    
    
    
    
    
    
	public void PrintName(point p, Graphics g)
    {
	Math.round(p.x);
	Math.round(p.y);
	int x = (int) p.x;
	int y = (int) p.y;
	g.drawString("Colby Rush, CS 384", x, y);
    }
	
	
    
    
    public matrix DefineCT(vector v, double theta, double phi, double alpha, double distance)
    {
     matrix CAMERA = DefineET(X_TRANS, (-1 * v.x));
     BuildET(CAMERA, Y_TRANS, (-1 * v.y));
     BuildET(CAMERA, Z_TRANS, (-1 * v.z));

     BuildET(CAMERA, Y_ROT, (-1 * theta));
     BuildET(CAMERA, X_ROT, phi);
     BuildET(CAMERA, Z_ROT, (-1 * alpha));

     BuildET(CAMERA, PERSPECTIVE, distance);
     
     return CAMERA;
    }


	public point ViewportToWindow(point vp)
    {
		 //v.x1 and x2 are viewport min and max, win follows same idea
		double x1 = (v.x2 - v.x1);  //set up similar triangle equation so it's not huge lower down
        double y1 = (v.y2 - v.y1);  //uses viewport sizes for this part
        double x2 = (v.x2 - v.x1) * f.getWidth();
        double y2 = (v.y2 - v.y1) * f.getHeight();

	    point p = new point(); //set coords for viewport into p
	    p.x = (((vp.x - v.x1) * x2) / x1) + w.x2;
	    p.y = (((vp.y - v.y1) * y2) / y1) + w.y2;
	    p.x = (f.getWidth() * v.x1) + p.x;
	    p.y = (f.getHeight() * (1 - v.y1)) - p.y;
	    
	        
	    return p;
    }

    
    public point WindowToViewport(double xwin, double ywin)
    {
        point p = new point(); //even more similar triangles
        p.x = (((xwin - w.x1) * (v.x2 - v.x1)) / (w.x1 - w.x2)) + v.x1;
        p.y = (((ywin - w.y1) * (v.y2 - v.y1)) / (w.x1 - w.y2)) + v.y1;
        return p;
    }


    public void Draw3D(vector v, matrix transM, matrix cameraTrans, Graphics g)
    {
      //you get the idea
      ApplyTransform(v, transM);
      ApplyTransform(v, cameraTrans);

      point p = WindowToViewport(v.x, v.y);

      p = ViewportToWindow(p); //converting coords to viewport and back again

      DrawTo(g,p);
    }

    
    public void DrawTo(Graphics g, point p)
    {
        g.drawLine((int)x, (int)y, (int)p.x, (int)p.y);
        x = p.x;
        y = p.y;
    }
    
    public void MoveTo(vector v)
    {
    	x = v.x;
    	y = v.y;
    	z = v.z;
    }
    
    public vector ApplyTransform(vector v, matrix transM)
    {
     double temp[] = new double[4];
     double vector[] = new double[4];
     vector[0] = v.x;
     vector[1] = v.y;
     vector[2] = v.z;
     vector[3] = 1; //vector to multiply with transform

     for( int i = 0; i < 4; i++ )
      for( int j = 0; j < 4; j++ )
       temp[i] += vector[j] * transM.matrix[i][j]; //weird requirement to access matrix elements

     v.x = temp[0];
     v.y = temp[1];
     v.z = temp[2];
     v.v = temp[3];
     return v;
    }

    

    public matrix BuildET(matrix transM, int transCode, double transVal)
    {
      matrix temp1 = new matrix(); 
      temp1 = DefineET(transCode, transVal); //loads up the matrix to multiply by into temp1
      transM = MultiplyM(transVal, temp1, transM);

      return transM;
     }
    
    public matrix MultiplyM(double transVal, matrix A, matrix B)
    {
    	matrix C = new matrix();
    	for (int i = 0; i < 4; i++)
    		for( int j = 0; j < 4; j++ )
    			for( int x = 0; x < 4; x++ )
    				C.matrix[i][j] += A.matrix[i][x] * B.matrix[x][j]; //weird restriction to get to matrix elements
		return C;
    }
    
    public matrix DefineET(int transCode, double transVal)
    {
    	
    	//big ugly if/else situation for giving identity ET matricies; refer to macros from above
      matrix m = new matrix();

      if (transCode == 0)
      {      
        m.SetMVal(0,0,1);
        m.SetMVal(0,1,0);
        m.SetMVal(0,2,0);
        m.SetMVal(0,3,transVal);
        m.SetMVal(1,0,0);
        m.SetMVal(1,1,1);
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
      	else if (transCode == 1)
      {      
      	m.SetMVal(0,0,1);
      	m.SetMVal(0,1,0);
      	m.SetMVal(0,2,0);
      	m.SetMVal(0,3,0);
      	m.SetMVal(1,0,0);
      	m.SetMVal(1,1,1);
      	m.SetMVal(1,2,0);
      	m.SetMVal(1,3,transVal);
      	m.SetMVal(2,0,0);
      	m.SetMVal(2,1,0);
      	m.SetMVal(2,2,1);
      	m.SetMVal(2,3,0);
      	m.SetMVal(3,0,0);
      	m.SetMVal(3,1,0);
      	m.SetMVal(3,2,0);
      	m.SetMVal(3,3,1);
       }
      	else if (transCode == 2)
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
        m.SetMVal(2,3,transVal);
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
		m.SetMVal(1,1,1);
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
	      else if (transCode == 4)
	      {      
	    m.SetMVal(0,0,1);
		m.SetMVal(0,1,0);
		m.SetMVal(0,2,0);
		m.SetMVal(0,3,0);
		m.SetMVal(1,0,0);
		m.SetMVal(1,1,transVal);
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
	      else if (transCode == 5)
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
		m.SetMVal(1,1,(Math.toDegrees(Math.cos(transVal))));
		m.SetMVal(1,2,(Math.toDegrees(Math.sin(transVal))));
		m.SetMVal(1,3,0);
		m.SetMVal(2,0,0);
		m.SetMVal(2,1,(Math.toDegrees(Math.sin(transVal)))*-1);
		m.SetMVal(2,2,(Math.toDegrees(Math.cos(transVal))));
		m.SetMVal(2,3,0);
		m.SetMVal(3,0,0);
		m.SetMVal(3,1,0);
		m.SetMVal(3,2,0);
		m.SetMVal(3,3,1);
	       }
	      else if (transCode == 7)
	      {      
	    m.SetMVal(0,0,(Math.toDegrees(Math.cos(transVal))));
		m.SetMVal(0,1,0);
		m.SetMVal(0,2,(Math.toDegrees(Math.sin(transVal))));
		m.SetMVal(0,3,0);
		m.SetMVal(1,0,0);
		m.SetMVal(1,1,1);
		m.SetMVal(1,2,0);
		m.SetMVal(1,3,0);
		m.SetMVal(2,0,(Math.toDegrees(Math.sin(transVal)))*-1);
		m.SetMVal(2,1,0);
		m.SetMVal(2,2,(Math.toDegrees(Math.cos(transVal))));
		m.SetMVal(2,3,0);
		m.SetMVal(3,0,0);
		m.SetMVal(3,1,0);
		m.SetMVal(3,2,0);
		m.SetMVal(3,3,1);
	       }
	      else if (transCode == 8)
	      {      
	    m.SetMVal(0,0,(Math.toDegrees(Math.cos(transVal))));
		m.SetMVal(0,1,(Math.toDegrees(Math.sin(transVal))));
		m.SetMVal(0,2,0);
		m.SetMVal(0,3,0);
		m.SetMVal(1,0,(Math.toDegrees(Math.sin(transVal)))*-1);
		m.SetMVal(1,1,(Math.toDegrees(Math.cos(transVal))));
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
		m.SetMVal(2,3,((1/transVal) * -1));
		m.SetMVal(3,0,0);
		m.SetMVal(3,1,0);
		m.SetMVal(3,2,0);
		m.SetMVal(3,3,1);
	       }
	      return m;
    }
    


}
