#include "Punto2D.h"

Punto2D::Punto2D()
{
    x.resize(0);
    y.resize(0);
}

Punto2D::Punto2D(int points)
{

  x.resize(points);
  y.resize(points);

}

void Punto2D::createPoints(int points)
{
    x.resize(points);
    y.resize(points);
    for(int i=0; i<points; i++)
    {
        this->x[i] = (rand()%620)-310;
    }

    for(int i=0; i<points; i++)
    {
        this->y[i] = (rand()%460)-230;
    }

    for(int i = 0; i < points; i++)
    {
       cout<<"X: "<<this->x[i]<<" Y: "<<this->y[i]<<endl;
    }

}


int Punto2D::getY(int value)
{
    return y[value];
}

int Punto2D::getX(int value)
{
    return x[value];
}

