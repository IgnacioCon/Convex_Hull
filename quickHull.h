#ifndef QUICKHULL_H
#define QUICKHULL_H

#include "Punto2D.h"
#include "math.h"
#include <algorithm>

class QuickHull
{

protected:

    vector<int> highestXY;
    vector<int> lowestXY;
    vector<int> convexHullX;
    vector<int> convexHullY;

public:

    QuickHull();

    int gethighestXY(int value);
    void sethighestXY(int value);

    int getlowestXY(int value);
    void setlowestXY(int value);

    int getConvexHullX(int value);
    void setConvexHullX(int value);

    int getConvexHullY(int value);
    void setConvexHullY(int value);


    void quickHull(Punto2D a);
    void findHull(Punto2D S, int P, int Q);

    int isLeft(Punto2D a, int m, int i, int o);
    void isRight();

    int getVectorSize();



};


#endif // QUICKHULL_H
