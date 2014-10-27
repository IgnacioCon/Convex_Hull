#include "Punto2D.h"

Punto2D::Punto2D()
{
    x = 0;
    y = 0;

}

void Punto2D::generarPunto()
{


  this->x = (rand()%401)-200;
  this->y = (rand()%401)-200;


}

float Punto2D::getY()
{
   return this->y;
}

float Punto2D::getX()
{
   return this->x;
}

void Punto2D::setXY(float x, float y)
{
  this->x = x;
  this->y = y;
}

