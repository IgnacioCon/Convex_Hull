#ifndef PUNTO2D_H
#define PUNTO2D_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Punto2D
{
protected:

    vector<int> x;
    vector<int> y;
public:

    Punto2D();
    Punto2D(int points);

    int getY(int value);
    int getX(int value);

    void createPoints(int points);
};












#endif // PUNTO2D_H
