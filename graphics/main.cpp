
/* basics
 *
 * A basic, first OpenGL program.
 *
 * This program illustrates how you open an window, specify its position and size,
 * and draw something in the window.
 *
 * Also illustrated: the state-machine operation of OGL. Notice that if you resize
 * the window, the box becomes blue -- the last color specified! This isn't the right
 * idea! Where should you put the color of the box?
 *
 * When you resize the window so it is not square, the box changes shape. This might
 * not be desired -- we will look into fixing this later. (Keep in mind, this has
 * something to do with the aspect ratio.)
 *
 * Try changing the size of gluOrtho2D -- see in code below -- and you'll see how the
 * relative size of the box changes within the window.
 *
 * See http://www.eas.asu.edu/~cse470/references.html for instruction on how to start
 * your own program
 *
 * Dianne Hansford, August 2004
 */


#include <stdio.h>

/* Include the GLUT library. This file (glut.h) contains gl.h and glu.h */
#include <GL/glut.h>

/* This is a debug file */
FILE *infofile;

/*
 * The rountine display() gets called each time the window is redrawn.
 */
void display()
{
	fprintf(infofile,"display: Entered \n");
	fflush(infofile);

	/* clear the screen*/
	glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_POLYGON);
    glRotatef(45.0f,0.0f,0,1.0);
	/* draw a filled polygon */
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0); //added color red
    glTranslatef(-0.5,-0.5,-0.5);
		glVertex2f(-0.5, -0.5);
		glVertex2f( 0.5, -0.5);
		glVertex2f( 0.5,  0.5);
		glVertex2f(-0.5,  0.5);
	glEnd();
    glLoadIdentity();

    glTranslatef(0,3.0f,0);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0); //added color red
    glVertex2f(-1, -1);
    glVertex2f( 0.2, 0.2);
    glVertex2f( 1,  4);
    glVertex2f( 2,  3);
    glVertex2f( 3,  -1);
    glEnd();
    glLoadIdentity();

    glTranslatef(0,-3.0f,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0); //added color red
    glVertex2f(-1, -1);
    glVertex2f( 0.2, 0.2);
    glVertex2f( 1,  -1);
    glEnd();
    glLoadIdentity();
	/* draw a fancy line -- red to blue variation in color */
	/* variation is created with linear interpolation */
	glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(-0.75, -0.75);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(0.75, -0.75);
	glEnd();
    //adding two more lines:
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-0.75, 0.75);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.75, 0.75);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.75, -0.75);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.75, 0.75);
    glEnd();

	/* ready to draw now! forces buffered OGL commands to execute */
	glFlush();

	fprintf(infofile,"display: Exit \n");
	fflush(infofile);
}

/* Initialize states -- called before */

void init()
{
	fprintf(infofile,"init: Entered \n");
	fflush(infofile);


	/* set background clear color to black */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/* set current color to white */
	glColor3f(1.0, 1.0, 1.0);

	/* identify the projection matrix that we would like to alter */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* the window will correspond to these world coorinates */
//	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

	/* we can play ... see what happens if we swap out this one with that above */
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);

	/* identify the modeling and viewing matrix that can be modified from here on */
	/* we leave the routine in this mode in case we want to move the object around */
	/* or specify the camera */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	fprintf(infofile,"init: Exit \n");
	fflush(infofile);
}

/* The main program */

int main(int argc, char** argv)
{
	/* Always a good idea to create a file to help you understand the program flow */
	/* Graphics programs can crash, so fflush is a good idea -- even if it slows things */
	infofile = fopen("infofile.txt", "w");
	fprintf(infofile,"basics.c -- a basic OpenGL program\n");
	fflush(infofile);

	/* create a window, position it, and name it */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(600, 600); //changed both to 600
	glutInitWindowPosition(800, 200); //changed position to 800,200
	glutCreateWindow("basics");

	fprintf(infofile,"Created windows\n");
	fflush(infofile);

	/* create a callback routine for (re-)display */
	glutDisplayFunc(display);

	/* init some states */
	init();

	/* entering the event loop */
	glutMainLoop();

	/* code here will not be executed */
}
