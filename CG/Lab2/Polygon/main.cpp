#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<GL/gl.h>

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
//glBegin(GL_POLYGON); // Draw A Quad
glBegin(GL_TRIANGLE_FAN);
glVertex3f(-0.1f, 0.1f, 0.1f); // Top Left
glVertex3f(-0.1f, 0.0f, 0.0f); // Left
glVertex3f(-0.1f, 0.0f, 0.0f); // Bottom Left
glVertex3f(0.1f, 0.0f, 0.0f); // Top Right
glVertex3f(0.0f, 0.1f, 0.1f); // Right
glVertex3f(0.1f, 0.0f, 0.1f); // Bottom Right
glEnd();
glFlush();
}

void init(void)
{
glClearColor(0.0,0.0,0.0,0.0);
}

void reshape(int w,int h)
{
   glViewport(0,0,w,h);
}

int main(int argc, char **argv)
{
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
