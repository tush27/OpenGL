#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

int xint, yint, x2, y2;

void plot(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}


void display() {
	int dx, dy, i, pk;
	int Xinc, Yinc;
	int x, y;

	dx = abs(x2 - xint);
	dy = abs(y2 - yint);

	Xinc = 1;
	Yinc = 1;

	if (x2 < xint)
		Xinc = -1;
	if (y2 < yint)
		Yinc = -1;

	glClear(GL_COLOR_BUFFER_BIT);
	x = xint;
	y = yint;
	plot(x, y);

	if (dx > dy) {
		
		pk = 2 * dy - dx;
		
		for (i = 0; i < dx; i++) {
			if (pk >= 0) {
				y += Yinc;
				pk += 2 * (dy - dx);
			}
			else
				pk += 2 * dy;
			x += Xinc;
			plot(x, y);
		}

	}
	else {
		
		pk = 2 * dx - dy;
		
		for (i = 0; i < dy; i++) {
			if (pk >= 0) {
				x += Xinc;
				pk += 2 * (dx - dy);
			}
			else
				pk += 2 * dx;
			y += Yinc;
			plot(x, y);
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

	cout << "Enter (x1, y1, x2, y2)\n";
	cin >> xint >> yint >> x2 >> y2;

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