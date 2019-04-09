#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

int pntX1, pntY1, a,b;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2f(x, y);

	glEnd();
}


void init(void)
{
	glClearColor(0.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glRotatef(30,10,10,0);
	//glTranslatef(0.10f,0.20f,0);
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}


void midptellipse(int rx, int ry,
                  int xc, int yc)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    // Initial decision parameter of region 1
    d1 = (ry * ry) - (rx * rx * ry) +
                     (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // For region 1
    while (dx < dy)
    {

        // Print points based on 4-way symmetry
        cout << x + xc << " , " << y + yc << endl;
        plot(x+xc,y+yc);
        cout << -x + xc << " , " << y + yc << endl;
        plot(-x+xc,y+yc);
        cout << x + xc << " , " << -y + yc << endl;
        plot(x+xc,-y+yc);
        cout << -x + xc << " , " << -y + yc << endl;
        plot(-x+xc,-y+yc);

        // Checking and updating value of
        // decision parameter based on algorithm
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    // Decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
         ((rx * rx) * ((y - 1) * (y - 1))) -
          (rx * rx * ry * ry);

    // Plotting points of region 2
    while (y >= 0)
    {

        // Print points based on 4-way symmetry
        cout << x + xc << " , " << y + yc << endl;
        plot(x+xc,y+yc);
        cout << -x + xc << " , " << y + yc << endl;
        plot(-x+xc,y+yc);
        cout << x + xc << " , " << -y + yc << endl;
        plot(x+xc,-y+yc);
        cout << -x + xc << " , " << -y + yc << endl;
        plot(-x+xc,-y+yc);

        // Checking and updating parameter
        // value based on algorithm
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);



	glFlush ();
}

void reshape(int w,int h)
{
   glViewport(0,0,w,h);
}

int main(int argc, char** argv)
{   int x,y;
	cout << "Enter the coordinates of the center:\n\n" << endl;

	cout << "X-coordinate   : "; cin >> x;
	cout << "\nY-coordinate : "; cin >> y;
	cout << "\nEnter radius : "; cin >> a;
	cout << "\nEnter radius : "; cin >> b;


	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
    glutCreateWindow("abcd");
	init ();
	midptellipse(a,b,x,y);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

}
