#ifndef PUNTO2D_H
#define PUNTO2D_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

class Punto2D
{
protected:

    int point;  //number of points
    vector<int> x;
    vector<int> y;
public:

    Punto2D();
    Punto2D(int points);

    int getY(int value);
    int getX(int value);
    void setX(int value);
    void setY(int value);
    int getPoint();
    void setPoint(int value);


    void savePoints(string c);
    void createPoints(int points);


};












#endif // PUNTO2D_H
