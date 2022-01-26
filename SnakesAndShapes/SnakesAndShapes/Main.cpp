#include <glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "snakes.h"
#include <stdlib.h>

#define COLUMNS 50
#define ROWS 50
#define FPS 7 //snake will move through 7 frames in one second

//Point to snake direction
extern short snakeDir;
bool endGame = false;

int points = 0;

void splashScreen();
void display();
void reshape(int,int);
void timer(int);
void gameControl(int, int, int);


void init()
{
	//background color
	glClearColor(0.0, 0.0, 0.2, 0.0);
	//initialize grid
	initGrid(COLUMNS, ROWS);
}

void splashScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRasterPos3d(-0.3, 0.6, 0);
	glColor3f(1.0, 1.0, 1.0);
	char message[]="WELCOME TO SNAKES AND SHAPES";
	for (int i = 0;i < strlen(message);i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);

	}
	glRasterPos3d(-0.3, 0.5, 0.0);
	glColor3f(0.7, 0.5, 0.1);
	char message2[] = "A FUN EDUCATIONAL GAME TO HELP KIDS LEARN ALL ABOUT SHAPES";
	for (int i = 0;i < strlen(message2);i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, message2[i]);
	}
	
	
	glRasterPos3d(-0.25, -0.7, 0.0);
	glColor3f(0.5, 0.6, 0.1);
	char message3[] = "PRESS 'x' TO START PLAYING!";
	for (int i = 0;i < strlen(message3);i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message3[i]);
	}

		
	glutSwapBuffers();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Grid();
	snake();
	food();
	glutSwapBuffers();
	if (endGame) {
		char _points[10];
		itoa(points, _points, 10);
		char text[50] = "Your total points: ";
		strcat(text, _points);
		MessageBox(NULL, text, "GAME OVER");
		exit(0);
	}
}

void reshape(int width, int height)
{
	glViewport(0,0,(GLsizei)width,(GLsizei)height); //Set the viewport of the window
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}



void keys(unsigned char key, int x, int y)
{
	if (key == 'x')
	{
		glutDisplayFunc(display);
		glutReshapeFunc(reshape); //Reshape callback
		glutTimerFunc(0, timer, 0);
		glutSpecialFunc(gameControl);
	}
	glutPostRedisplay(); //Call the display function as soon as possible
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/FPS, timer, 0);
} 

void gameControl(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (snakeDir != DOWN)
			snakeDir = UP;
		break;
	case GLUT_KEY_DOWN:
		if (snakeDir != UP)
			snakeDir = DOWN;
		break;
	case GLUT_KEY_RIGHT:
		if (snakeDir != LEFT)
			snakeDir = RIGHT;
		break;
	case GLUT_KEY_LEFT:
		if (snakeDir != RIGHT)
			snakeDir = LEFT;
		break;
	}
}

//MAIN FUNCTION
int main(int argc, char** argv)
{
	glutInit(&argc, argv); //Initialize glut library
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); //Initialize display mode
	glutCreateWindow("Snakes and Shapes"); //Create the display window
	glutInitWindowSize(500, 500); //Set size of diplay window
	glutInitWindowPosition(100, 100); //Set the position of the display window
	glutDisplayFunc(splashScreen);//Dispaly callback for the current window
	glutKeyboardFunc(keys);
	init();
	glutMainLoop(); //Keep calling display functions and window is displayed
	return 0;
	
}

