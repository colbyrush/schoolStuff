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
void drawString (void * font, char *s, float x, float y, float z);

/* Window width and height */
int winW = 640;
int winH = 640;
/* Rendering state variables */
int aniOn = 0;
int fillOn = 1;


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

void drawString (void * font, char *s, float x, float y, float z) //handles text requests
{
     unsigned int i;
     glRasterPos3f(x, y, z);

     for (i = 0; i < strlen (s); i++)
          glutBitmapCharacter (font, s[i]);
}

double makeRadius(double x,double y)
{
	double r;

	r = sqrt(pow(x,2) + pow(y,2));
	return r;
}

double makeTheta(double x, double y)
{
	double theta;

	theta = atan(y/x);
	return theta;
}

void drawModel(void) //draws 3D function
{
	double x,y,z1,z2,radius,theta = 0;

	glBegin(GL_QUADS);
	for(x = -2; x < 2; x+=.05) //graphs the function
		for(y = 0; y < 6.28318; y+=.0628318)
		{
			radius = makeRadius(x,y);
			theta = makeTheta(x,y);
			z1 = (3*pow(2.71828182845904523536, pow(-radius,2)))*(sin(6.28318*(radius)) - ((radius)*cos(3*theta)));
			glVertex3f(x,y,z1);
		}
	glEnd();

}

void drawName()
{
	glColor3f(1.0,1.0,1.0);
    drawString(GLUT_BITMAP_HELVETICA_18, "Colby Rush - CS 324 Assignment 6", 0, 0, 0); 
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

	 glTranslatef(0,0,-10);
	 drawModel();            

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
