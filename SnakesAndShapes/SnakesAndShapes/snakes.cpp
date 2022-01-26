#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "snakes.h"
#include <ctime>

extern int points

//Drawing grid on screen
int gridX, gridY;

//snake length
int snakeLength = 5;

//snake positions
int positionX[60]=(20,20,20,20,20), positionY[60]=(20,19,18,17,16);
short snakeDir = RIGHT;


extern int point;
extern bool endGame;
bool food1= true;

//position of food
int foodX, foodY;

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

void food() 
{
	if (food)
		random(foodX, foodY);
	food1 = false;
	glColor3f(1.0, 0.5, 0.0);
	glRectf(foodX, foodY, foodX + 1, foodY + 1);
}

void snake()
{
	for (int i = snakeLength - 1; i > 0; i--)
	{
		positionX[i] = positionX[i - 1];
		positionY[i] = positionY[i - 1];

	}

	//drawing the snake
	if (snakeDir == UP)
		positionY[0]++;
	else if (snakeDir == DOWN)
		positionY[0]--;
	else if (snakeDir == RIGHT)
		positionX[0]++;
	else if (snakeDir == LEFT)
		positionX[0]--;
	for (int i = 0; i < snakeLength; i++)
	{
		if (i = 0)
			glColor3f(0.0, 1.0, 0.0);
		else
			glColor3f(1.0, 0.0, 0.0);
		glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
	}
	
	if (positionX[0] == 0 || positionX[0] = gridX - 1 || positionY[0] == 0 || positionY[0] == gridY - 1)
		endGame = true;
	if (positionX[0] = foodX && positionY[0] = foodY)
	{
		points++;
		snakeLength++;
		if (snakeLength > MAX)
			snakeLength = MAX;
		food1 = true;
	}
		
}
 

void random(int &x, int &y)
{
	int _maxX = gridX - 2;
	int _maxY = gridY - 2;
	int _min = 1;
	srand(time(NULL));
	x = _min + rand() % (_maxX - _min);
	y = _min + rand() % (_maxY- _min);
		
}
	