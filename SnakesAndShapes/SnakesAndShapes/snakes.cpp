#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "snakes.h"
#include <ctime>

extern int scores;

//Drawing grid on screen
int gridX, gridY;
//food variables
bool foodObj = true;
int foodX, foodY;

//snake variables
int sLength = 3;
int positionX[70]={25,25,25,25,25}, positionY[70]={25,24,23,22,21};
short snakeDir = RIGHT;
extern bool gameOver;


void square(int, int);

void initGrid(int x, int y)
{
	gridX = x;
	gridY = y;
}



void Grid()
{
	//Drawing the grid
	for (int x = 0; x < gridX; x++)
	{
		for (int y = 0; y < gridY; y++)
		{
			square(x, y);
		}
	}
}

//drawing a single square unit of the grid
void square(int x, int y)
{
	if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1)
	{
		glLineWidth(2.5);
		glColor3f(1.0, 1.0, 0.0);
	}
	else
	{
		glLineWidth(1.0);
		glColor3f(0.0, 0.0, 0.2);
	}

	glBegin(GL_LINE_LOOP);

	 glVertex2f(x, y);
	 glVertex2f(x + 1, y);
	 glVertex2f(x+1, y+1);
	 glVertex2f(x, y+1);


	glEnd();
}

//drawing the snake's object
void food()
{
	if (foodObj)
		random(foodX, foodY);
	foodObj = false;
	
	glColor3f(0.5, 1.2, 0.7);

	glRectf(foodX, foodY, foodX + 1, foodY + 1);
}

void snake()
{
	//drawing the snake
	for(int i = sLength-1; i > 0; i--)
	{
		positionX[i] = positionX[i-1];
		positionY[i] = positionY[i-1];
	}
	if (snakeDir == UP)
		positionY[0]++;
	else if (snakeDir == DOWN)
		positionY[0]--;
	else if (snakeDir == RIGHT)
		positionX[0]++;
	else if (snakeDir == LEFT)
		positionX[0]--;

	for (int i = 0; i < sLength; i++)
	{
		if (i == 0)
		{
			glColor3f(1.0, 0.2, 0.6);
		}
		else if (i == 1)
		{
			glColor3f(1.0, 0.2, 0.6);
			glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
		}
		else if (i == 2)
		{
			glColor3f(0.7, 0.5, 0.6);
			glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
		}
		else if (i == 3)
		{
			glColor3f(0.5, 0.3, 0.4);
			glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
		}
		else if (i == 4)
		{
			glColor3f(0.3, 0.1, 0.2);
			glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
		}
		else if (i == 5)
		{
			glColor3f(0.1, -0.1, 0.0);
			glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
		}
		else if (i == 6)
		{
			glColor3f(0.7, 0.8, 0.9);
			glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
		}
		else if (i == 7)
		{
			glColor3f(0.5, 0.6, 0.7);
			glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
		}
		else if (i == 8)
		{
			glColor3f(0.3, 0.4, 0.5);
			glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
		}
		else if (i == 9)
		{
			glColor3f(0.1, 0.2, 0.3);
			glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
		}
		else
		{
			glColor3f(0.4, 0.0, 0.1);
			glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
		}
	}

	if (positionX[0] == 0 || positionX[0] == gridX - 1 || positionY[0] == 0 || positionY[0] == gridY - 1)
		gameOver = true;

	if (positionX[0] == foodX && positionY[0] == foodY)
	{
		scores++;
		sLength++;
		if (sLength > MAXL)
			sLength = MAXL;
		foodObj = true;
	}
}

void random(int& x, int& y)
{
	int maximumX = gridX - 2;
	int maximumY = gridY - 2;
	int minimum = 1;
	srand(time(NULL));
	x = minimum + rand() % (maximumX - minimum);
	y = minimum + rand() % (maximumY - minimum);
}
	