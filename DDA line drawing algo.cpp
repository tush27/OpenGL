#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;
GLdouble X1, Y1, X2, Y2;

void display() {

	GLfloat step, dx, dy,Xinc, Yinc;
	GLdouble x,y;

	dx = X2 - X1;
	dy = Y2 - Y1;

	step = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
	Xinc = dx / step;
	Yinc = dy / step;

	x = X1; y = Y1;
	glClear(GL_COLOR_BUFFER_BIT);						//previous color from the buffer is cleared
	glBegin(GL_POINTS);
	glVertex2d(x, y);

	for (int i=0; i < step; ++i)
	{
		x += Xinc;
		y += Yinc;
		glVertex2d(x, y);
	}
	glEnd();
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
	cout << "Enter X1: ";
	cin >> X1;
	cout << "Enter Y1: ";
	cin >> Y1;
	cout << "Enter X2: ";
	cin >> X2;
	cout << "Enter Y2: ";
	cin >> Y2;

	glutInit(&argc, argv);								//initializes the communication between window and application(visual studio here)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		//specify whether to use RGB or color indexed values in single or double buffered window
	glutInitWindowPosition(0, 0);						//specify the starting location of the window
	glutInitWindowSize(640, 480);						//defines the size of window
	glutCreateWindow("MySelfPrac");						//creates window and returns int id
	Initializer();										//self-defined function to give window properties
	glutDisplayFunc(display);							//pass the function name which we want to display
	
	glutMainLoop();										//makes the window to hold our output
	return 0;
}