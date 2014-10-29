#include <iostream>
#include "Punto2D.h"
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

void display();
void init();
void reshape(int width,int height);

Punto2D a;

int points;
int main(int argc, char **argv)
{
    srand(time(NULL));

    cout<<"Input number of points to plot: "; cin>>points;
    a.createPoints(points);

    glutInit(&argc, argv); //Begin to use GLUT
    //Begin display
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100,100);
    //Window size
    glutInitWindowSize(640,480);
    glutCreateWindow("Window");
    init();
    glutDisplayFunc(display); //Begin visualization of the image
    glutReshapeFunc(reshape);

    glutMainLoop();


    return 0;
}


void display()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-320, 320, 240, -240, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.375, 0.375, 0);
    glPointSize(2);
    glBegin(GL_POINTS);

    for(int i = 0; i< points;i++)
    {
        glVertex2s(a.getX(i),a.getY(i));

    }
    glEnd();
    glFlush();
    glutPostRedisplay();
}


void init()
{
   glClearColor(0.0,0.0,0.0,0.0); //Esta funcion recive un valor RGBA
}

void reshape(int width,int height)
{
   // printf("%d %d\n",width,height);

    glViewport(0,0,width,height);

    //https://www.opengl.org/sdk/docs/man2/xhtml/glMatrixMode.xml
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-10.0f,10.0f,-10.0f,10.0f,-1.0f,1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glutPostRedisplay();
}

