#ifndef GIFTWRAP_H
#define GIFTWRAP_H

#include <GL/gl.h>
#include <GL/glut.h>

#include "Punto2D.h"

class GiftWrap
{

protected:

   vector<int> convexHullX;
   vector<int> convexHullY;


public:
    GiftWrap();
    int getConvexHullY(int value);
    void setConvexHullY(int value);
    int getConvexHullX(int value);
    void setConvexHullX(int value);

    void calcConvexHull(Punto2D a);
    int leftTurn(Punto2D a, int m, int i, int o);
    int getVectorSize();

    void pintado(GiftWrap b);

};

#endif // GIFTWRAP_H
