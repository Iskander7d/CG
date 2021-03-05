#pragma once

#include <GL/glut.h>

namespace utils
{
	void reshape(int w, int h)
	{
		if (h == 0)
			h = 1;
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		float ratio = w / (float)h;
		if (w <= h)
			glOrtho(-100, 100, -100 / ratio, 100 / ratio, 1, -1);
		else
			glOrtho(-100 * ratio, 100 * ratio, -100, 100, 1, -1);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void changePosition(float &x, float&y, float xDirection, float yDirection, float multiplier)
	{
		x += xDirection * multiplier;
		y += yDirection * multiplier;
	}

	void exitOnEscape(unsigned char key, int x, int y)
	{
		if (key == 27)
		{
			exit(0);
		}
	}
}