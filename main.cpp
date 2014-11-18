#include <iostream>
#include "Punto2D.h"
#include "giftwrap.h"
#include "quickHull.h"
using namespace std;

void display();
void init();
void reshape(int width,int height);
void keyboard(unsigned char key,int x, int y);

Punto2D a, d;
GiftWrap b;
QuickHull c;
int red = 1;
int blue = 0;
int points;
int main(int argc, char **argv)
{
    srand(time(NULL));
    cout<<"                                   CONVEX HULL"<<endl;
    cout<<"Press A to display GiftWrap Algorithm.\nPress B to display QuickHull Algorithm.\nPress D to exit."<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"Input number of points to plot: "; cin>>points;
    a.createPoints(points);

    b.calcConvexHull(a);
    c.quickHull(a);


    glutInit(&argc, argv); //Begin to use GLUT
    //Begin display
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(170,100);
    //Window size
    glutInitWindowSize(640,480);
    glutCreateWindow("Window");
    init();
    glutDisplayFunc(display); //Begin visualization of the image
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);//Keyboard
    glutMainLoop();


    return 0;
}


void display()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-400, 400, 400, -400, 0, 1);
    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3f(1,1,0);

     //glVertex2s(0,0);
    for(int i = 0; i< points;i++)
    {
        glVertex2s(a.getX(i),a.getY(i)*(-1));

    }
    glEnd();

    d.displayConvexHull(red,blue);

    glFlush();
    glutPostRedisplay();
}


void init()
{
   glClearColor(0.0,0.0,0.0,0.0);
}

void reshape(int width,int height)
{

    glViewport(0,0,width,height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-10.0f,10.0f,-10.0f,10.0f,-1.0f,1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glutPostRedisplay();
}

void keyboard(unsigned char key,int x, int y)
{
    switch(key)
    {
    case 'd': //Exit
        exit(0);
        break;
    case 'a':
        //Set color line to Red
        red = 1;    blue = 0;
        //Display Convex Hull Calculated by Giftwrap
        d = b.copyConvexHull();
        cout<<"GiftWrap"<<endl;
        break;
    case 's':
        //Set color line to Blue
        red = 0;    blue = 1;

        //Display convex hull calculated by QuickHull
        d = c.copyConvexHull();
        cout<<"QuickHull"<<endl;
        break;
    }
}

