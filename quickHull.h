#ifndef QUICKHULL_H
#define QUICKHULL_H

#include "Punto2D.h"

class QuickHull
{

protected:

int max_x;
int min_x;
int max_y;
int min_y;
vector<int> QHullX;
vector<int> QHullY;
vector <int> PosX;
vector <int> PosY;
vector <int> izquierdo;
vector <int> derecho;
vector <int> puntosQuickHull;


public:

QuickHull();
void calcQuickHull(Punto2D a);
void calcularPuntosCriticos(Punto2D a);
void determinarPuntosParticiones(Punto2D a);
void determinarPuntosIzquierdo(Punto2D a);
void determinarPuntosDerecho(Punto2D a);


};


#endif // QUICKHULL_H
