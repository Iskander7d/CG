#pragma once
#include <GL/glut.h>
#include <cmath>

bool rotateCube = false;

float rotateX = 0.0f;
float rotateY = 0.0f;
float rotateZ = 0.0f;

float a = 0;

float ax = 0;
float ay = 0;
float az = 0;

bool rx = false;
bool ry = false;
bool rz = false;

void renderCG3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(0, 0, -300);

	if (rx)
		glRotatef(ax, 1.0f, 0.0f, 0.0f);
	if (ry)
		glRotatef(ay, 0.0f, 1.0f, 0.0f);
	if (rz)
		glRotatef(az, 0.0f, 0.0f, 1.0f);

	glBegin(GL_LINE_STRIP);
	glVertex3f(-50, -50, -50);
	glVertex3f(50, -50, -50);
	glVertex3f(50, 50, -50);
	glVertex3f(-50, 50, -50);
	glVertex3f(-50, -50, -50);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-50, -50, 50);
	glVertex3f(50, -50, 50);
	glVertex3f(50, 50, 50);
	glVertex3f(-50, 50, 50);
	glVertex3f(-50, -50, 50);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-50, -50, 50);
	glVertex3f(-50, -50, -50);
	glVertex3f(50, -50, 50);
	glVertex3f(50, -50, -50);
	glVertex3f(50, 50, 50);
	glVertex3f(50, 50, -50);
	glVertex3f(-50, 50, 50);
	glVertex3f(-50, 50, -50);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

void timer3(int = 0)
{
	renderCG3();
	glutTimerFunc(10, timer3, 0);
}

void keyboardRotateControl(unsigned char key, int x, int y)
{
	rotateCube = true;

	switch (key)
	{
	case 'w':
		++ax;
		rx = true;
		break;
	case 's':
		--ax;
		rx = true;
		break;
	case 'a':
		++ay;
		ry = true;
		break;
	case 'd':
		--ay;
		ry = true;
		break;
	case 'q':
		++az;
		rz = true;
		break;
	case 'e':
		--az;
		rz = true;
		break;
	default:
		break;
	}
}


void cg3()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Cube");
	glClearColor(0, 0, 0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45, 1, 0, 100);
	glutDisplayFunc(renderCG3);

	glutKeyboardFunc(keyboardRotateControl);

	timer3();
	glutMainLoop();
}
