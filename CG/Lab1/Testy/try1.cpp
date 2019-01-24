#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<GL/gl.h>

void display()
{
glClear(GL_COLOR_BUFFER_BIT);

glFlush();
}

void init(void)
{
glClearColor(0.0,1.0,0.0,0.0);
}

void reshape(int w,int h)
{
   glViewport(0,0,w,h);
}
public void try1(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(10,100);
    glutCreateWindow("First Window");
    init();
    glutDisplayFunc(display);
   glutReshapeFunc(reshape);
    glutMainLoop();


}


















































