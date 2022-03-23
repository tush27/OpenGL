#include <iostream>
#include<GL/glut.h>
using namespace std;

void rect() {
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.9, -0.3);
	glVertex2f(-0.3, -0.3);
	glVertex2f(-0.3, 0.3);
	glVertex2f(-0.9, 0.3);
	glEnd();
	glFlush();
}

void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

	glColor3f(1,1,0);
	rect();
	glColor3f(1,0,0);
	glTranslatef(0.7, -0.3, 0.0);
	rect();
	glColor3f(0,1,0);
	glTranslatef(0.0, 0.7, 0.0);
	rect();
	glColor3f(0,0,1);
	glTranslatef(-0.3, -0.3, 0.0);
	rect();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("RectTransform");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}