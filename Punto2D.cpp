#include "Punto2D.h"
#include<fstream>

Punto2D::Punto2D()
{
    x.resize(0);
    y.resize(0);
}

Punto2D::Punto2D(int points)
{

    this->p = points;
  x.resize(p);
  y.resize(p);

}

void Punto2D::createPoints(int points)
{
    this->p = points;
    x.resize(p);
    y.resize(p);
    for(int i=0; i<p; i++)
    {
        this->x[i] = (rand()%620)-310;
    }

    for(int i=0; i<p; i++)
    {
        this->y[i] = (rand()%460)-230;
    }

    for(int i = 0; i < p; i++)
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

void Punto2D::salvar(string c)
{

      ofstream file;
      file.open(c.c_str());
      if(file.is_open())
      {
          file <<"(x,y)"<<endl;
                for(int i = 0;i<this->p;i++)
                {
                      file <<"("<<this->x[i]<<","<<this->y[i]<<")"<<endl;

                }


        file.close();
      }

}
