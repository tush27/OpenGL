#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;
void rectangle(int x1, int y1, int x2, int y2)
{
	glBegin(GL_POLYGON);
	glVertex2i(x1, y1);
	glVertex2i(x1, y2);
	glVertex2i(x2, y2);
	glVertex2i(x2, y1);
	glEnd();
	glFlush();
}
void circle(float x1, float y1, double radius) {
	float x2, y2;
	float angle;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		x2 = x1 + sin(angle) * radius;
		y2 = y1 + cos(angle) * radius;
		glVertex2f(x2, y2);
	}
	glEnd();
	glFlush();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.59, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2i(100, 200);
	glVertex2i(200, 350);
	glVertex2i(200, 200);
	glEnd();
	glFlush();

	glColor3f(1.0, 1.0, 0.0);
	rectangle(200, 200, 400, 350);
	glColor3f(0.0, 0.0, 1.0);
	rectangle(400, 200, 550, 450);
	glColor3f(1.0, 1.0, 0.0);
	rectangle(425, 350, 525, 425);
	glColor3f(1.0, 0.0, 0.0);
	rectangle(250, 350, 300, 380);
	glColor3f(0.0, 0.0, 1.0);
	rectangle(225, 380, 325, 410);

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(225, 410);
	glVertex2i(250, 440);
	glVertex2i(300, 440);
	glVertex2i(325, 410);
	glEnd();
	glFlush();

	glColor3f(1.0, 0.0, 0.0);
	circle(210, 150, 50);
	circle(310, 150, 50);
	circle(485, 165, 65);
	glColor3f(1.0, 1.0, 0.0);
	circle(485, 165, 30);
	glColor3f(0.0, 0.0, 1.0);
	rectangle(200, 130, 515, 150);
}

void Initializer()
{
	glClearColor(1.0, 1.0, 1.0, 0);						//sets background color
	glMatrixMode(GL_PROJECTION);						//changes the state of the system (PROJECTION or MODELVIEW)
	glLoadIdentity();									//clears the projection matrix
	gluOrtho2D(0, 640, 0, 480);							//viewer can see only the objects which are inside (0,0)and (640,480)
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);								//initializes the communication between window and application(visual studio here)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		//specify whether to use RGB or color indexed values in single or double buffered window
	glutInitWindowPosition(0, 0);						//specify the starting location of the window
	glutInitWindowSize(640, 480);						//defines the size of window
	glutCreateWindow("MySelfPrac");						//creates window
	Initializer();										//self-defined function to give window properties
	glutDisplayFunc(display);							//pass the function name which we want to display
	glutMainLoop();										//makes the window to hold our output
	return 0;
}