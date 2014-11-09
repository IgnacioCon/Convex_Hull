#include "Punto2D.h"



int Punto2D::getPoint()
{
    return point;
}

void Punto2D::setPoint(int value)
{
    point = value;
}
Punto2D::Punto2D()
{
    point = 0;
    x.resize(0);
    y.resize(0);
}

Punto2D::Punto2D(int points)
{

  this->point = points;
  x.resize(points);
  y.resize(points);

}

void Punto2D::createPoints(int points)
{
    this->point = points;   x.resize(this->point);   y.resize(this->point); //receive number of points and resize the vectors accordingly

    for(int i=0; i<this->point; i++)
        {
            this->x[i]=(rand()%620)-310; //assign random numbers from -310 to 310
        }

    for(int i=0; i<this->point; i++)
        {
            this->y[i]=(rand()%460)-230;  //assgin random numbers from -230 to 230
        }

    for(int i = 0; i < this->point; i++)
        {
            cout<<"X: "<<this->x[i]<<" Y: "<<this->y[i]<<endl;
        }

}


int Punto2D::getY(int value)
{
    return y[value]; //get a value from the vector
}

int Punto2D::getX(int value)
{
    return x[value]; //get a value from the vector
}

void Punto2D::setX(int value)
{
    x.push_back(value); //set a value
}

void Punto2D::setY(int value)
{
    y.push_back(value); //set a value
}

void Punto2D::savePoints(string c)
{

      ofstream file;
      file.open(c.c_str());
      if(file.is_open())
      {
          file <<"(x,y)"<<endl;
          for(int i = 0;i<this->point;i++)
            {
               file <<"("<<this->x[i]<<","<<this->y[i]<<")"<<endl;
            }


        file.close();
      }

}



