#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "snakes.h"

//Drawing grid on screen
int gridX, gridY;

//snake positions
int positionX = 25, positionY = 25;
short snakeDir = RIGHT;


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

void snake()
{
	//drawing the snake
	if (snakeDir == UP)
		positionY++;
	else if (snakeDir == DOWN)
		positionY--;
	else if (snakeDir == RIGHT)
		positionX++;
	else if (snakeDir == LEFT)
		positionX--;

	glRectd(positionX, positionY, positionX + 1, positionY + 1);
}
	