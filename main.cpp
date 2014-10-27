#include <iostream>
#include "Punto2D.h"

using namespace std;

int main()
{
    srand(time(NULL));

    Punto2D a;
    Punto2D b;
    Punto2D c;

    a.generarPunto();
    b.generarPunto();
    c.generarPunto();

    cout<<"Punto 1"<<endl;
    cout<<"X = "<<a.getX()<<" Y = "<<a.getY()<<endl;

    cout<<"Punto 2"<<endl;
    cout<<"X = "<<b.getX()<<" Y = "<<b.getY()<<endl;

    cout<<"Punto 3"<<endl;
    cout<<"X = "<<c.getX()<<" Y = "<<c.getY()<<endl;




    return 0;
}

