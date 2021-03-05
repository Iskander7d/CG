#pragma once

#include <iostream>
#include <GL/glut.h>
#include "utils.hpp"

using namespace std;

bool isRotate = false;
float x = 0;
float y = 0;
float moving_x = 0;
float moving_y = 0;
float multiplier = 7.0f;


void renderCG2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-25.0f + x, 25.0f + y, 25.0f + x, -25.0f + y);

	if (isRotate)
		glRotatef(5.0f, 0.0f, 0.0f, 1.0f);

	if (moving_x || moving_y)
		utils::changePosition(x, y, moving_x, moving_y, multiplier);

	glFlush();
}

void timer(int = 0)
{
	renderCG2();
	glutTimerFunc(36, timer, 0);
}


void keyboardControl(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;

	case 'w':
		moving_y = 0.1f;
		break;
	case 's':
		moving_y = -0.1f;
		break;
	case 'a':
		moving_x = -0.1f;
		break;
	case 'd':
		moving_x = 0.1f;
		break;
	}
}

void keyboardInv(unsigned char key, int x, int y)
{
	if (key == 'w' || key == 's') {
		moving_y = 0;
	}
	else if (key == 'a' || key == 'd') {
		moving_x = 0;
	}
}

void setRotateStatus(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		isRotate = true;
	else if (button == GLUT_RIGHT_BUTTON)
		isRotate = false;
}


void cg2()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);

	glutCreateWindow("sizeable square");
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1, 0, 100);

	glutDisplayFunc(renderCG2);
	glutReshapeFunc(utils::reshape);

	glutKeyboardFunc(keyboardControl);
	glutKeyboardUpFunc(keyboardInv);
	glutMouseFunc(setRotateStatus);

	timer();
	glutMainLoop();

}
