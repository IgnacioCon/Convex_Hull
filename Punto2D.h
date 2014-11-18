#ifndef PUNTO2D_H
#define PUNTO2D_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <algorithm>
#include <GL/gl.h>
#include <GL/glut.h>


using namespace std;

class Punto2D
{
protected:

    int point;  //number of points
    vector<int> x;
    vector<int> y;
    vector<int> convHullX;
    vector<int> convHullY;

public:


    Punto2D();
    Punto2D(int points);

    int getY(int value);
    int getX(int value);
    void setX(int value);
    void setY(int value);
    int getPoint();
    void setPoint(int value);

    void setConvexHullX(int value);
    int getConvexHullX(int value);
    void setConvexHullY(int value);
    int getConvexHullY(int value);

    void savePoints(string c);
    void clearVector();
    void createPoints(int points);
    int getVectorSize();


    void printConvex();
    void displayConvexHull(int r, int b);

};












#endif // PUNTO2D_H
