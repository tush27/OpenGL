#include<iostream>
#include<GL/glut.h>

using namespace std;

int Xc, Yc, r;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x + Xc, y + Yc);
	glEnd();
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);

	int x = 0;
	int y = r;
	float pk = 3 - 2 * r;		//decision parameter
	
	plot(x, y);
	plot(x, -y);
	plot(y, x);
	plot(-y, x);

	while (y > x)
	{
		if (pk < 0)
		{
			pk += 4 * x + 6;
		}
		else
		{
			pk += 4 * (x - y) + 10;
			y--;
		}
		x++;

		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
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

	cout << "Enter the coordinates of the center:\n\n" << endl;
	cout << "X-coordinate   : "; cin >> Xc;
	cout << "\nY-coordinate : "; cin >> Yc;
	cout << "\nEnter radius : "; cin >> r;

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