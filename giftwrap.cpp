#include "giftwrap.h"


GiftWrap::GiftWrap()
{
}


int GiftWrap::getConvexHullY(int value)
{
    return convexHullY[value];
}

void GiftWrap::setConvexHullY(int value)
{
    convexHullY.push_back(value);
}

void GiftWrap::setConvexHullX(int value)
{
    convexHullX.push_back(value);

}

int GiftWrap::getConvexHullX(int value)
{
    return convexHullX[value];
}


void GiftWrap::calcConvexHull(Punto2D a)
{
    /*We find the first and leftmost point of the convexHull*/

    int index=0;
    for(int i=0;i<a.getPoint();i++)
    {
        if(a.getX(i)<a.getX(index))
        {
             index = i; //keep track of where the leftmost point is
        }
    }

    //Insert the first coordinate into the Convex Hull
    this->convexHullX.push_back(a.getX(index));
    this->convexHullY.push_back(a.getY(index));

    int m = index;
    int o; //m is starting point, index is sentinel, and o is random point
    int c = 1; //number of points in convex hull

    //Begin search for the Convex Hull
    do
    {
       //look for o, to calculate if it is counterclockwise for all points i
       o = (m+1)%a.getPoint();
       for (int i = 0; i < a.getPoint(); i++)
       {
         if(leftTurn(a, m, i, o) == 2)
            {
                o = i;
            }
       }

       this->convexHullX.push_back(a.getX(o));
       this->convexHullY.push_back(a.getY(o));

       m = o; // Set m as the next point
       c++;   //increase number of convex hull coordinates
    }while (m != index);

    cout<<"Convex Hull"<<endl;
    for(int i = 0; i < c; i++)
        {
            cout<<"X: "<<this->convexHullX[i]<<" Y: "<<this->convexHullY[i]<<endl;
        }

}


//m is first point, i is second point, o is third point
int GiftWrap::leftTurn(Punto2D a, int m, int i, int o)
{
    int result;

    result = ((a.getY(i)-a.getY(m))*(a.getX(o)-a.getX(i)))-((a.getY(o)-a.getY(i))*(a.getX(i)-a.getX(m)));

    if(result == 0)
    {
        return 0;	//collinear
    }

    return  (result>0)? 1:2; //if greater than 0, clockwise, else counterclockwise

}

int GiftWrap::getVectorSize()
{
    return convexHullX.size();

}



