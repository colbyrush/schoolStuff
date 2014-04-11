/*
     Computer Graphics Assignment 5

     File        -- Assign5.c
     Date        -- 4/11/2014
     Author      -- Colby Rush

     Partially based off Nate Miller's cube tutorial in code and format.
*/


#include <stdio.h>
#include <GL/freeglut.h>
#include <math.h>

/*
     This is my vertex structure
     0 = x, 1 = y, 2 = Z
*/
typedef float vec3_t[3];

/* Window width and height */
int winW = 640;
int winH = 640;
/* Rendering state variables */
int aniOn = 0;
int fillOn = 1;

void drawString (void * font, char *s, float x, float y, float z);

/* Vertex data for our cube */
vec3_t cube[] =
{
     {-1,-1, 1},
     { 1,-1, 1},
     { 1, 1, 1},
     {-1, 1, 1},

	 {-1, 1, 1},
     { 1, 1, 1},
     { 1, 1,-1},
     {-1, 1,-1},

     {-1,-1,-1},
     { 1,-1,-1},
     { 1, 1,-1},
     {-1, 1,-1},

     {-1,-1, 1},
     { 1,-1, 1},
     { 1,-1,-1},
     {-1,-1,-1},

	 {-1, 1,-1},
     {-1,-1,-1},
     {-1,-1, 1},
     {-1, 1, 1},
     

     { 1,-1,-1},
     { 1,-1, 1},
     { 1, 1, 1},
     { 1, 1,-1},
};

vec3_t hallway[] =
{
     {-5,-6, -25}, //left side to gap
     {-5,-6, 5},
     {-5, 6, 5},
     {-5, 6, -25},

	 {-5,-6,13}, //left side from gap
	 {-5,6,13},
	 {-5,6,25},
	 {-5,-6,25},

	 {-5,-6,5}, //office box wall
	 {-5,6,5},
	 {-13,6,5},
	 {-13,-6,5},

	 {-5,-6,13}, //office box wall
	 {-5,6,13},
	 {-13,6,13},
	 {-13,-6,13},

	 {-5,-6,5}, //office box floor
	 {-13,-6,5},
	 {-13,-6,13},
	 {-5,-6,13},

	 {-5,6,5}, //office box ceiling
	 {-13,6,5},
	 {-13,6,13},
	 {-5,6,13},

	 {-5, 6, 25}, //top
     { 5, 6, 25},
     { 5, 6,-25},
     {-5, 6,-25},

     {5,-6,-25}, //right
     {5,-6,25},
     {5, 6,25},
     {5, 6,-25},

     {-5,-6,-25}, //bottom
     {-5,-6,25},
     {5,-6,25},
     {5,-6,-25},

	 {-5,-6,7}, //pillar front
	 {-5,6,7},
	 {-5,6,10},
	 {-5,-6,10},

	 {-7,-6,7}, //pillar back
	 {-7,6,7},
	 {-7,6,10},
	 {-7,-6,10},

	 {-5,-6,7}, //pillar side
	 {-5,6,7},
	 {-7,6,7},
	 {-7,-6,7},

	 {-5,-6,10}, //pillar side
	 {-5,6,10},
	 {-7,6,10},
	 {-7,-6,10},


};
/* Colors for our cube */
vec3_t colors[] =
{
	 //red
     {1.0f, 0.0f, 0.0f},
	 {1.0f, 0.0f, 0.0f},
	 {1.0f, 0.0f, 0.0f},
	 {1.0f, 0.0f, 0.0f},
	 
	 //green
	 {0.0f, 1.0f, 0.0f},
	 {0.0f, 1.0f, 0.0f},
	 {0.0f, 1.0f, 0.0f},
	 {0.0f, 1.0f, 0.0f},

	 //blue
	 {0.0f, 0.0f, 1.0f},
	 {0.0f, 0.0f, 1.0f},
	 {0.0f, 0.0f, 1.0f},
	 {0.0f, 0.0f, 1.0f},

	 //white
	 {1.0f, 1.0f, 1.0f},
	 {1.0f, 1.0f, 1.0f},
	 {1.0f, 1.0f, 1.0f},
	 {1.0f, 1.0f, 1.0f},
	 
	 //yellow
	 {1.0f, 1.0f, 0.0f},
	 {1.0f, 1.0f, 0.0f},
	 {1.0f, 1.0f, 0.0f},
	 {1.0f, 1.0f, 0.0f},

	 //orange
	 {1.0f, 0.5f, 0.0f},
	 {1.0f, 0.5f, 0.0f},
	 {1.0f, 0.5f, 0.0f},
	 {1.0f, 0.5f, 0.0f},


};
/* Amount to rotate */
vec3_t rot = {0,0,0};
/* Position of our eye or camera */
vec3_t eye = {0,0,30};


void drawModel(void) //draws the hallway model
{
	int i = 0;
	glBegin(GL_QUADS);
	for (i = 0; i < 56; i ++)
		 {
			 glColor3fv(colors[i % 12]);
			 glVertex3fv(hallway[i]);
		 }
	glEnd();

}

void drawCube2(void) //draws the solid cube
{
     int i,x,y,z;

	 for (x = 0; x < 3; x++) //x axis cubes
	 {
		 glBegin(GL_QUADS);
		 for (i = 0; i < 24; i ++)
		 {
			 glColor3fv(colors[i]);
			 glVertex3fv(cube[i]);
		 }

		 for (y = 0; y < 3; y++) //y axis cubes
		 {
			  glBegin(GL_QUADS);
			  for (i = 0; i < 24; i ++)
			  {
				glColor3fv(colors[i]);
				glVertex3fv(cube[i]);
			  }

		 for (z = 0; z < 3; z++) //z axis cubes
		 {
			  glBegin(GL_QUADS);
			  for (i = 0; i < 24; i ++)
			  {
				glColor3fv(colors[i]);
				glVertex3fv(cube[i]);
			  }
			glEnd();
			glTranslatef(0,0,2); //account for z
		  }

		  glEnd();
		  glTranslatef(0,2,-6); //account for y with z offset
		  }

		  glEnd();
		  glTranslatef(2,-6,0); //account for x with y offset
	 }
}

void drawCube(void) //draws spaced cube
{
     int i,x,y,z;

	 for (x = 0; x < 3; x++) //x axis cubes
	 {
		 glBegin(GL_QUADS);
		 for (i = 0; i < 24; i ++)
		 {
			 glColor3fv(colors[i]);
			 glVertex3fv(cube[i]);
		 }

		 for (y = 0; y < 3; y++) //y axis cubes
		 {
			  glBegin(GL_QUADS);
			  for (i = 0; i < 24; i ++)
			  {
				glColor3fv(colors[i]);
				glVertex3fv(cube[i]);
			  }

		 for (z = 0; z < 3; z++) //z axis cubes
		 {
			  glBegin(GL_QUADS);
			  for (i = 0; i < 24; i ++)
			  {
				glColor3fv(colors[i]);
				glVertex3fv(cube[i]);
			  }
			glEnd();
			glTranslatef(0,0,2.5); //account for z
		  }

		  glEnd();
		  glTranslatef(0,2.5,-7.5); //account for y with z offset
		  }

		  glEnd();
		  glTranslatef(2.5,-7.5,0); //account for x with y offset
	 }
}

void drawFuncP(void) //draws first function with GL_POINTS
{
	double i;
	glPointSize(3.0f);
	glColor3f(1.0, 0.0, 0.0); // Red
    glBegin(GL_POINTS);

	for (i = -3.14159; i <= 9.42477; i+=.01)
	    glVertex2f( (i), (pow(2.71828182845904523536,(-.2*i)) * sin(3*i)));
    
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	    //axes
		glVertex2f(0,3);
		glVertex2f(0,-3);
		glVertex2f(-4,0);
		glVertex2f(10,0);
	
		//labels
		glVertex2f(-.3, 2);
		glVertex2f(.3,2);
		glVertex2f(-.3,-2);
		glVertex2f(.3,-2);
		glVertex2f(-3,.3);
		glVertex2f(-3,-.3);
		glVertex2f(3,.3);
		glVertex2f(3,-.3);
		glVertex2f(6,.3);
		glVertex2f(6,-.3);

	glEnd();

	    // labels
		glColor3f(1.0, 1.0, 1.0);
		drawString(GLUT_BITMAP_HELVETICA_18, "6", 6, .5, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "3", 3, .5, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "2", .4, 2, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "-2", .25, -2, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "-3", -3, .5, 0);
}

void drawFuncL(void)
{
	double i;
	glLineWidth(3.0f);
	glColor3f(1.0, 0.0, 0.0); // Red
    glBegin(GL_LINES);

	for (i = -3.14159; i <= 9.42477; i+=.01)
	    glVertex2f( (i), (pow(2.71828182845904523536,(-.2*i)) * sin(3*i)));
    
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	    //axes
		glVertex2f(0,3);
		glVertex2f(0,-3);
		glVertex2f(-4,0);
		glVertex2f(10,0);
	
		//labels
		glVertex2f(-.3, 2);
		glVertex2f(.3,2);
		glVertex2f(-.3,-2);
		glVertex2f(.3,-2);

		glVertex2f(-3,.3);
		glVertex2f(-3,-.3);
		glVertex2f(3,.3);
		glVertex2f(3,-.3);
		glVertex2f(6,.3);
		glVertex2f(6,-.3);

	glEnd();

	    //labels
		glColor3f(1.0, 1.0, 1.0);
		drawString(GLUT_BITMAP_HELVETICA_18, "6", 6, .5, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "3", 3, .5, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "2", .4, 2, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "-2", .25, -2, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "-3", -3, .5, 0);
}

void drawFunc3d(void) //draws 3D function
{
	double x,y,z = 0;
	double smallest = 9999999;
	double biggest = -9999999;

	for(x = -5; x < 5; x+=.1)  //pre-calculates largest and smallest to be used later
		for(y = -5; y < 5; y+=.1)
		{
			z = (6*sin(2*x + 3*cos(3*y))*pow(2.71828182845904523536, (-.5*(pow(x,2) + pow(y,2)))));
			if (z > biggest)
				biggest = z;
			else if (z < smallest)
				smallest = z;
		}

	glBegin(GL_QUADS);
	for(x = -5; x < 5; x+=.1) //graphs the function. If within "big" range, paints red, if "small", paint blue. Paint rest purple
		for(y = -5; y < 5; y+=.1)
		{
			z = (6*sin(2*x + 3*cos(3*y))*pow(2.71828182845904523536, (-.5*(pow(x,2) + pow(y,2)))));
			if (z >= biggest - 3.5)
				glColor3f(1.0,0,0);
			else if (z <= smallest + 3.5)
				glColor3f(0.0,0,1.0);
			else
				glColor3f(0.5,0,0.5);
			glVertex3f(x,y,z);
		}
	glEnd();

}

void drawString (void * font, char *s, float x, float y, float z) //handles text requests
{
     unsigned int i;
     glRasterPos3f(x, y, z);

     for (i = 0; i < strlen (s); i++)
          glutBitmapCharacter (font, s[i]);
}

void drawName()
{
	glColor3f(1.0,1.0,1.0);
    drawString(GLUT_BITMAP_HELVETICA_18, "Colby Rush - CS 324 Assignment 5", 0, 0, 0); 
}

/*
=============
glutDisplay
=============

Our main display function.  This will clear the color and depth buffers.  After
that it will translate the world to our eye position and rotate it by the
rotation amounts.  Finally the cube is drawn and the buffers are swapped.
*/
void glutDisplay( void ) //main function. All functions are commented out unless wanted to be displayed, mostly for screenshots. Doesn't really work nicely together.
{
     glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

     glMatrixMode( GL_MODELVIEW );
     glLoadIdentity();

     glTranslatef( -eye[0], -eye[1], -eye[2] );

     glRotatef( rot[0], 1.0f, 0.0f, 0.0f );
     glRotatef( rot[1], 0.0f, 1.0f, 0.0f );
     glRotatef( rot[2], 0.0f, 0.0f, 1.0f );

	 glTranslatef(-4,-5,20);
	 drawFuncP();
	 glTranslatef(0,9,0);
	 drawFuncL();

	 glTranslatef(0,0,20);
	 drawFunc3d();            

	 glTranslatef(0,0,-10);
	 drawModel();

	 glTranslatef(-10,0,10);
     drawCube();
	 glTranslatef(10,0,0);
	 drawCube2();

	 drawName();

     glutSwapBuffers();
}
/*
=============
clamp
=============

Used to keep the rotations in the range of -360 to 360
*/
void clamp( vec3_t p )
{
     int i;

     for (i = 0; i < 3; i ++)
         if (p[i] >= 360 || p[i] < -360)
             p[i] = 0;
}
/*
=============
glutIdle
=============

The idle function that animates our cube.  Advances the rotation variables.
*/
void glutIdle(void)
{
     if (aniOn)
     {
         rot[0] += 0.7f;
         rot[1] += 0.5f;
         rot[2] += 0.3f;

         clamp(rot);
         glutPostRedisplay();
     }
}
/*
=============
glutResize
=============

Called when the application starts by default and when the window is resized.
When called the winW and winH are updated.  Then the depth and color buffers
are cleared and a viewing projection is established.  The viewing projection
needs to be set only when the width and height of the window change.
*/
void glutResize (int w, int h)
{
     if (!h)
        return;

     winW = w;
     winH = h;

     glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
     glViewport( 0, 0, winW, winH );

     glMatrixMode( GL_PROJECTION );
     glLoadIdentity();

     gluPerspective( 90, winW / winH, 1, 9999 );

     glutPostRedisplay();
}
/*
=============
glutKeyboard
=============

Handles keyboard input.
*/
void glutKeyboard( unsigned char key, int x, int y )
{
     switch (key)
     {
     case ' ':
             aniOn = !aniOn;
             break;
     case 'f':
     case 'F':
             fillOn = !fillOn;

             if (fillOn)
                 glPolygonMode(GL_FRONT_AND_BACK, GL_FILL );
             else
                 glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

             glutPostRedisplay();

             break;
     case 'h':
     case 'H':
             printf("Space Bar -- On/Off Animation\n");
             printf("f         -- On/Off Wireframe\n");
             break;

     }
}
/*
=============
glInit
=============

Sets up depth test and tells opengl to fill our polys.
*/
void glInit(void)
{
     glEnable( GL_DEPTH_TEST );
     glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}

int main( int argc, char** argv )
{
     glutInit( &argc, argv ); 

     glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
     glutInitWindowSize( winW, winH );

     glutCreateWindow( "Assignment 5" ); 
     glutDisplayFunc( glutDisplay );
     glutReshapeFunc( glutResize );
     glutIdleFunc( glutIdle );
     glutKeyboardFunc( glutKeyboard );

     glInit();
     glutMainLoop();

     return 0;
}
