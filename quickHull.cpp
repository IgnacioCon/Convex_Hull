#include "quickHull.h"
#include <math.h>

QuickHull::QuickHull()
{
    max_x = -100000;
    min_x = 100000;
    max_y = -100000;
    min_y = 100000;
}

void QuickHull::calcQuickHull(Punto2D a)
{
    int i = 0;
    int j = 0;

   this->calcularPuntosCriticos(a);
    cout<<"Quick Hull"<<endl;
    cout<<"Max X = "<<a.getX(this->PosX[0])<<" Min X = "<<a.getX(this->PosX[1])<<endl;
    cout<<"Max Y = "<<a.getY(this->PosY[0])<<" Min Y = "<<a.getY(this->PosY[1])<<endl;

    this->determinarPuntosParticiones(a);


    cout<<"Size Izquierdo = "<<this->izquierdo.size()<<endl;
    cout<<"Size Derecho = "<<this->derecho.size()<<endl;

    cout<<"Izquierdo"<<endl;

    for(i=0;i<this->izquierdo.size();i++)
    {
        cout<<this->izquierdo[i]<<endl;
    }

    cout<<"Derecho"<<endl;

    for(i=0;i<this->derecho.size();i++)
    {
        cout<<this->derecho[i]<<endl;
    }

    this->determinarPuntosIzquierdo(a);
    this->determinarPuntosDerecho(a);

    cout<<"Izquierdo"<<endl;

    for(i=0;i<this->izquierdo.size();i++)
    {
        cout<<this->izquierdo[i]<<endl;
    }

    this->izquierdo.erase(izquierdo.begin());
    this->izquierdo.erase(izquierdo.begin());


    cout<<"Izquierdo"<<endl;

    for(i=0;i<this->izquierdo.size();i++)
    {
        cout<<this->izquierdo[i]<<endl;
    }




}

void QuickHull::calcularPuntosCriticos(Punto2D a)
{
    int i = 0;
    int j = 0;
    int aux = 0;
    int posxMax = 0;
    int posxMin = 0;
    int posyMax = 0;
    int posyMin = 0;

    while(i<a.getPoint())
    {
        if(a.getX(i)>=this->max_x)
        {
            this->max_x = a.getX(i);
            posxMax = i;

        }

        i++;
    }

    i = 0;

    while(i<a.getPoint())
    {
        if(a.getX(i)<=this->min_x)
        {
            this->min_x = a.getX(i);
            posxMin = i;

        }

        i++;
    }

    i = 0;

    while(i<a.getPoint())
    {
        if(a.getY(i)>=this->max_y)
        {
            this->max_y = a.getY(i);
            posyMax = i;

        }

        i++;
    }

    i = 0;

    while(i<a.getPoint())
    {
        if(a.getY(i)<=this->min_y)
        {
            this->min_y = a.getY(i);
            posyMin = i;

        }

        i++;
    }

    this->PosX.push_back(posxMax);
    this->PosX.push_back(posxMin);
    this->PosY.push_back(posyMax);
    this->PosY.push_back(posyMin);

}

void QuickHull::determinarPuntosParticiones(Punto2D a)
{
    int P1x = a.getX(this->PosX[1]); //Corrdenada X Punto minimo X
    int P1y = a.getY(this->PosX[1]); //Coordenada Y Punto minimo X

    int P2x = a.getX(this->PosX[0]); //Coordenada X Punto maximo x
    int P2y = a.getY(this->PosX[0]); //Coordenada Y punto maximo x

    cout<<"Punto Maximo: X = "<<P2x<<" Y = "<<P2y<<endl;
    cout<<"Punto Minimo: X = "<<P1x<<" Y = "<<P1y<<endl;

    double distancia = 0; //negativo a la izquierda recta, positivo derecha de la recta
    int i = 0;

    this->izquierdo.push_back(P1x);
    this->izquierdo.push_back(P1y);
    this->izquierdo.push_back(P2x);
    this->izquierdo.push_back(P2y);

    this->derecho.push_back(P1x);
    this->derecho.push_back(P1y);
    this->derecho.push_back(P2x);
    this->derecho.push_back(P2y);

    for(i=0;i<a.getPoint();i++)
    {
        if(P1x == a.getX(i))
            distancia = 0;
        else if(P2x == a.getX(i))
            distancia = 0;
        else
        {
          distancia = (a.getY(i)-P2y)*P1x + (P2x-a.getX(i)*P1y) + (a.getX(i)*P2y-a.getY(i)*P2x);

          if(distancia>=0)
          {
                  this->derecho.push_back(a.getX(i));
                  this->derecho.push_back(a.getY(i));
          }

          else
          {

                  this->izquierdo.push_back(a.getX(i));
                  this->izquierdo.push_back(a.getY(i));
          }



        }
    }


}

void QuickHull::determinarPuntosIzquierdo(Punto2D a)
{
   int sizeVectorI = this->izquierdo.size();
   cout<<"Size Izquierdo "<<sizeVectorI<<endl;
   double areaMaxima = -2000;
   int i = 0;
   double area = 0;
   double s = 0;
   float P1x = this->izquierdo[0];
   float P1y = this->izquierdo[1];
   float P2x = this->izquierdo[2];
   float P2y = this->izquierdo[3];
   float P3x = 0;
   float P3y = 0;
   double distancia1 = 0;
   double distancia2 = 0;
   double distancia3 = 0;
   int nuevox = 0;
   int nuevoy = 0;

   for(i=4;i<sizeVectorI;i = i+2)
   {

           P3x = this->izquierdo[i];
           P3y = this->izquierdo[i+1];
          distancia1 = sqrt((P2x-P1x)*(P2x-P1x)+(P2y-P1y)*(P2y-P1y));
          distancia2 = sqrt((P3x-P2x)*(P3x-P2x)+(P3y-P2y)*(P3y-P2y));
          distancia3 = sqrt((P3x-P1x)*(P3x-P1x)+(P3y-P1y)*(P3y-P1y));

          s = (distancia1+distancia2+distancia3)/2;
          area = sqrt(s*(s-distancia1)*(s-distancia2)*(s-distancia3));

          if(area>=areaMaxima)
          {
              areaMaxima = area;
              nuevox = this->izquierdo[i]; ;
              nuevoy = this->izquierdo[i+1];
          }

          cout<<"Area = "<<area<<endl;
   }

   cout<<"Area Maxima = "<<areaMaxima<<" X = "<<nuevox<<" Y ="<<nuevoy<<endl;


}

void QuickHull::determinarPuntosDerecho(Punto2D a)
{
    int sizeVectorI = this->derecho.size();
    cout<<"Size Derecho "<<sizeVectorI<<endl;
    double areaMaxima = -2000;
    int i = 0;
    double area = 0;
    double s = 0;
    float P1x = this->derecho[0];
    float P1y = this->derecho[1];
    float P2x = this->derecho[2];
    float P2y = this->derecho[3];
    float P3x = 0;
    float P3y = 0;
    double distancia1 = 0;
    double distancia2 = 0;
    double distancia3 = 0;
    int nuevox = 0;
    int nuevoy = 0;

    for(i=4;i<sizeVectorI;i = i+2)
    {

            P3x = this->derecho[i];
            P3y = this->derecho[i+1];
           distancia1 = sqrt((P2x-P1x)*(P2x-P1x)+(P2y-P1y)*(P2y-P1y));
           distancia2 = sqrt((P3x-P2x)*(P3x-P2x)+(P3y-P2y)*(P3y-P2y));
           distancia3 = sqrt((P3x-P1x)*(P3x-P1x)+(P3y-P1y)*(P3y-P1y));

           s = (distancia1+distancia2+distancia3)/2;
           area = sqrt(s*(s-distancia1)*(s-distancia2)*(s-distancia3));

           if(area>=areaMaxima)
           {
               areaMaxima = area;
               nuevox = this->derecho[i]; ;
               nuevoy = this->derecho[i+1];
           }

           cout<<"Area = "<<area<<endl;
    }

    cout<<"Area Maxima = "<<areaMaxima<<" X = "<<nuevox<<" Y ="<<nuevoy<<endl;

}
