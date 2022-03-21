#include<iostream>
#include<GL/glut.h>

using namespace std;
GLdouble rx, ry, xc, yc;

void plot(GLdouble x, GLdouble y) {

	glBegin(GL_POINTS);
	glVertex2d(x + xc, y + yc);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	GLdouble x, y, decision, rx_square, ry_square, dx, dy;
	x = 0;
	y = ry;

	rx_square = rx * rx;
	ry_square = ry * ry;


	decision = ry_square - rx_square * ry + (rx_square / 4);
	dx = 2 * ry_square * x;
	dy = 2 * rx_square * y;

	while (dx < dy) {

		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);

		if (decision < 0) {
			x++;
			dx = 2 * ry_square * x;
			decision += dx + ry_square;
		}
		else
		{
			x++; y--;
			dx = 2 * ry_square * x;
			dy = 2 * rx_square * y;
			decision += dx - dy + ry_square;
		}

	}

	decision = ry_square * (x + 0.5) * (x + 0.5) + rx_square * (y - 1) * (y - 1) - rx_square * ry_square;

	while (y >= 0) {
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);

		if (decision > 0)
		{
			y--;
			dy = 2 * rx_square * y;
			decision += rx_square - dy;

		}
		else
		{
			x++;
			y--;
			dy += -2 * rx_square;
			dx += 2 * ry_square;
			decision += dx - dy + rx_square;

		}
	}

	glFlush();
}

void Initializer() {
	glClearColor(1.0, 1.0, 1.0, 0);						//sets background color
	glColor3f(1.0, 0.0, 0.0);							//sets the drawing color
	glMatrixMode(GL_PROJECTION);						//changes the state of the system (PROJECTION or MODELVIEW)
	glLoadIdentity();									//clears the projection matrix
	gluOrtho2D(0, 640, 0, 480);							//viewer can see only the objects which are inside (0,0)and (640,480)
}

int main(int argc, char** argv) {

	cout << "Enter center coordinates: ";
	cin >> xc >> yc;
	cout << "Enter rx,ry: ";
	cin >> rx >> ry;

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

