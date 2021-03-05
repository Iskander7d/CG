#pragma once
#include <iostream>
#include <GL/glut.h>
#include "utils.hpp"

using namespace std;

void renderCG1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-25.0f, 25.0f, 25.0f, -25.0f);
	glFlush();
}


void cg1()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);

	glutCreateWindow("sizeable square");
	glutDisplayFunc(renderCG1);
	glutReshapeFunc(utils::reshape);
	glutKeyboardFunc(utils::exitOnEscape);
	glClearColor(0, 0, 0, 0);

	glutMainLoop();
}