#ifndef PUNTO2D_H
#define PUNTO2D_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Punto2D
{

  protected:

    float x;
    float y;



  public:

    Punto2D();
    void generarPunto();
    float getY();
    float getX();
    void setXY(float x, float y);





};












#endif // PUNTO2D_H
