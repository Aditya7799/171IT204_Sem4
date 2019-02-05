#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<GL/gl.h>
float x1,x2,y1,y2;


void display()
{
glClear(GL_COLOR_BUFFER_BIT);
int m_new = 2 * (y2 - y1);
   int slope_error_new = m_new - (x2 - x1);
   for (int x = x1, y = y1; x <= x2; x++)
   {
    glBegin(GL_POINTS);
    glColor3f(1,1,1);
    glVertex2i(x,y);
    glEnd();
    slope_error_new += m_new;
    if (slope_error_new >= 0)
      {
         y++;
         slope_error_new  -= 2 * (x2 - x1);
      }
   }



glFlush();
}

void init(void)
{
glClearColor(0,0,0,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}

void reshape(int w,int h)
{
   glViewport(0,0,w,h);
}

int main(int argc, char **argv)
{
    x1=10.0;
    x2=20.0;
    y1=10.0;
    y2=25.0;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("First Window");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;

}
