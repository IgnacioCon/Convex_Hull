#ifndef QUICKHULL_H
#define QUICKHULL_H

#include <GL/gl.h>
#include <GL/glut.h>

#include "Punto2D.h"

class QuickHull
{

private:

    vector<int> QHullX;
    vector<int> QHullY;

public:

    QuickHull();
    int getQHullY(int value);
    void setQHullY(int value);
    int getQHullX(int value);
    void setQHullX(int value);

    void QHull(Punto2D a);
    void pintar(QuickHull c);
    int  getVectorSize();



};


#endif // QUICKHULL_H
