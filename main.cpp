#include <iostream>
#include "Punto2D.h"
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

void display();
void init();

Punto2D a;
Punto2D b;
Punto2D c;

int main(int argc, char **argv)
{
    srand(time(NULL));



    a.generarPunto();
    b.generarPunto();
    c.generarPunto();

    cout<<"Punto 1"<<endl;
    cout<<"X = "<<a.getX()<<" Y = "<<a.getY()<<endl;

    cout<<"Punto 2"<<endl;
    cout<<"X = "<<b.getX()<<" Y = "<<b.getY()<<endl;

    cout<<"Punto 3"<<endl;
    cout<<"X = "<<c.getX()<<" Y = "<<c.getY()<<endl;

    glutInit(&argc, argv); //Begin to use GLUT
    //Begin display
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100,100);
    //Window size
    glutInitWindowSize(640,480);
    glutCreateWindow("Window");
    init();
    glutDisplayFunc(display); //Begin visualization of the image

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
    glPointSize(10);
    glBegin(GL_POINTS);

    glVertex2s(a.getX(), a.getY());
    glVertex2s(b.getX(),b.getY());
    glVertex2s(c.getX(),c.getY());


    glEnd();
    glFlush();
    glutPostRedisplay();
}


void init()
{
    //int b=600;
    // glMatrixMode(GL_PROJECTION);
    //glClearColor(0.0,0.0,0.0,0.0);
    // gluOrtho2D(-b,b,500,-500);
    glClearColor(0.0,0.0,0.0,0.0); //Esta funcion recive un valor RGBA
}

