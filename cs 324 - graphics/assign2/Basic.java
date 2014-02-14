/* CS 324.Bolden.........Javac SE 7u51...........Colby Rush
 * 2/14/2014 .................Computer & CPU.............cooby.rush@gmail.com
 *
 * Basic program to get familiar with java and primitive graphic functions.
 *---------------------------------------------------------------------
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;



public class Basic extends JComponent
{
     // default values
     int frameWidth  = 500;
     int frameHeight = 500;

     int xcoord = 0; //universal xcoord
     int ycoord = 0; //universal ycoord

     Color [] lineColors = { Color.black, Color.red,   Color.green,
                             Color.blue,  Color.orange, Color.magenta };

     public static void main( String[] args )
     {
	Basic start = new Basic();
        start.InitGraphics(); //starts the program
     }


     public void InitGraphics()
     {     
     JFrame f = new JFrame( "Basic" );
     


         //  Exit application when the window is closed
     f.addWindowListener( new WindowAdapter() 
      {
       public void windowClosing(WindowEvent e)
       {  System.exit(0); }
      }
      );

      f.setSize(frameWidth, frameHeight);         //initilizes the window
      f.getContentPane().add(new Basic());
      f.setVisible(true);
     }

     public void Plot(Graphics g)
     {

     int frameWidth  = getWidth();
     int frameHeight = getHeight();

      //equation 1
      MoveTo2D(250,250);
      for (double x = 0; x <= 3*(Math.PI) ; x+=.05)
      {
       int y = (int)((20*(4.0*(Math.pow(Math.E, -0.25*x)))*(Math.cos(4*x))));
       int intx = (int)(20*x);
       DrawTo2D(g, y+100, intx+275, 3);
      }

       g.setColor( lineColors[0] );
       g.drawLine(275, 100, frameWidth-20, 100);
       g.drawLine(275, 10, 275, 200);

      //equation 2
      MoveTo2D(0, 0);
      for (double x = -9; x <= 9 ; x+=.0001)
      {
       int y = (int)(5*(2/(0.5 - Math.sin(x/2))));
       int intx = (int)(x*5);
       DrawTo2D(g, y+225, intx+115, 5);
      }

       g.setColor( lineColors[0] );
       g.drawLine(120, 50, 120, frameHeight - 50);
       g.drawLine(10 , 220, 240, 220);

      //equation 3
      //3.1
      MoveTo2D(250, 250);
      for (double x = 0; x <= 8 ; x+=.001)
      {
       int y = -1*((int)(6*Math.sqrt((.5)*(Math.pow(x,3)) + (.5)*Math.pow(x,2))));
       int intx = (int)(x*30);
       DrawTo2D(g, y+450, intx+250, 0);
      }
         
      //3.2
      MoveTo2D(250, 250);
      for (double x = 0; x <= 8 ; x+=.001)
      {
       int y = -1*((int)(6*Math.sqrt(Math.pow(x,3) + (.5)*Math.pow(x, 2))));
       int intx = (int)(x*30);
       DrawTo2D(g, y+450, intx+250, 1);
      }      
      
      //3.3
      MoveTo2D(250, 250);
      for (double x = 0; x <= 8 ; x+=.001)
      {
       int y = -1*((int)(6*Math.sqrt((2)*Math.pow(x,3) + (.5)*Math.pow(x ,2))));
       int intx = (int)(x*30);
       DrawTo2D(g, y+450, intx+250, 2);
      }      

       g.setColor( lineColors[0] );
       g.drawLine(255, frameHeight-10, frameWidth-20, frameHeight-10);
       g.drawLine(255, 275, 255, frameHeight-10);


     }


     public void DrawTo2D(Graphics g, int newxcoord, int newycoord, int iColor) //sends 2D coords to drawLines
     {
      //sends new known coords to line drawing
      drawLines(g, newxcoord, newycoord, iColor);
      MoveTo2D(newxcoord, newycoord);
     }


     public void drawLines( Graphics g, int knowny, int knownx, int iColor) //draws the lines
     {

         // Draws axes
         g.setColor( lineColors[0] );
	 g.drawLine(frameWidth/2, frameHeight/2, frameWidth, frameHeight/2);
	 g.drawLine(frameWidth/2, 0, frameWidth/2, frameHeight);
        
         g.setColor( lineColors[iColor] );
	 //draws actual lines for next line segment
 	 g.drawLine(knownx, knowny, knownx, knowny);

     }    


     public void MoveTo2D(int newxcoord, int newycoord) //sets universal coords to next point to draw from
     {
      //sets default coords to place you want to go
      xcoord = newxcoord;
      ycoord = newycoord;
     }


     public void paintComponent(Graphics g) //paints picture
     {
         //makes frame and name
         frameWidth  = getWidth();
         frameHeight = getHeight();

         int x = frameWidth/2;
         int y = frameHeight/2;
         
         g.drawString( "Colby Rush - CS 324", x, y );
         g.drawString( "Equation 2", 175, 250 );
         g.drawString( "Equation 1", 320, 200 );
         g.drawString( "Equation 3", 270, 400 );


         Plot(g);
     }















}
