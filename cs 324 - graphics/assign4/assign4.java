/* CS 324.Bolden.........Javac SE 7u51...........Colby Rush
 * 3/14/2014 ............ .............cooby.rush@gmail.com
 *
 * Basic 3D images
 *----------------------------------------------------------
 */

import java.awt.Graphics;

import javax.swing.JComponent;

public class assign4 extends JComponent
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	/**
	 * 
	 */
	
    static int frameWidth = 700;
    static int frameHeight = 700;
    double x;
    double y;

    public static void main( String[] args)
    {
    	
	backend.InitGraphics();
    }
   
    
    public void paintComponent( Graphics g)
    {	
	// Create first window
    window w1 = backend.DefineWindow(-1.25, -1.25, 1.25, 1.25, -1, -1, 1, 1);
    point p = backend.WindowToViewport(w1, -1.25, 0);
	p = backend.ViewportToWindow(w1, p);

    matrix graph = new matrix();
    graph = backend.DefineET(graph, 0, 0);
    matrix camera = backend.DefineCT(1, 1, 1, 0, 0, 0, 1);
	backend.Move3D(w1, p, graph, camera);

	for(double i = -1.5; i < 1.25 ; i = i+.01)
	{
	 for(double j = -1.5; j < 1.25 ; j= j+.01)
	 {
		 p.SetX(i);
		 p.SetY(j);
		 p.SetZ(Math.pow(i, 2) + Math.pow(j, 2) - Math.pow(i, 3) - 8*(i)*(Math.pow(j, 4)));
           backend.Draw3D(w1, p, graph, camera, g);
	 }
	 

    }
    }



	public void PrintName(point p, Graphics g)
    {
	Math.round(p.x);
	Math.round(p.y);
	int x = (int) p.x;
	int y = (int) p.y;
	g.drawString("Colby Rush, CS 384", x, y);
    }

}
