#include "quickHull.h"


QuickHull::QuickHull()
{
    highestXY.clear();
    lowestXY.clear();
    convexHullX.clear();
    convexHullY.clear();

}

int QuickHull::getConvexHullX(int value)
{
    return convexHullX[value];
}

void QuickHull::setConvexHullX( int value)
{
    this->convexHullX.push_back(value);
}



int QuickHull::getConvexHullY(int value)
{
    return convexHullY[value];
}

void QuickHull::setConvexHullY( int value)
{
    this->convexHullY.push_back(value);
}


void QuickHull::sethighestXY(int value)
{
    highestXY.push_back(value);

}

int QuickHull::gethighestXY(int value)
{
    return highestXY[value];
}

int QuickHull::getlowestXY(int value)
{
    return lowestXY[value];
}

void QuickHull::setlowestXY(int value)
{
      lowestXY.push_back(value);
}

void QuickHull::quickHull(Punto2D a)
{
    Punto2D S1, S2;


    //Find the highest and lowest vertical point
    int index = 0;
    for(int i=0;i<a.getPoint();i++)
    {
        if(a.getY(i)>a.getY(index))
        {
             index = i; //keep track of where the highest point is
        }
    }


    //Save coordinate to HighestXY
    this->highestXY.push_back(a.getX(index));    this->highestXY.push_back(a.getY(index));

    int index2 = 0;
    for(int i=0;i<a.getPoint();i++)
    {
        if(a.getY(i)<a.getY(index2))
        {
             index2 = i; //keep track of where the lowest point is
        }
    }

    //Save to lowestXY
    this->lowestXY.push_back(a.getX(index2));   this->lowestXY.push_back(a.getY(index2));

    //Save the initial points of the the two new partitions S1 and S2
    S1.setX(a.getX(index));     S1.setY(a.getY(index));
    S1.setX(a.getX(index2));    S1.setY(a.getY(index2));

    S2.setX(a.getX(index2));    S2.setY(a.getY(index2));
    S2.setX(a.getX(index));     S2.setY(a.getY(index));

    int p1 = 2; int p2 =2;
    for(int i=0; i<a.getPoint(); i++)
    {
        if(isLeftOrRight(a, index, i, index2) == 1)
        {
            S1.setX(a.getX(i));         //S1 has all points left of segment HighestXY to LowestXY
            S1.setY(a.getY(i));
            p1++;
        }
        else if(isLeftOrRight(a, index2, i, index) == 1)
        {
            S2.setX(a.getX(i));         //S2 has all points right of segment HighestXY to LowestXY
            S2.setY(a.getY(i));
            p2++;
        }

    }

    //Set the number of points in the new partitions
    S1.setPoint(p1);    S2.setPoint(p2);

    //Find the Convex Hull
    findHull(S1, 0, 1);
    findHull(S2, 1, 0);




    //Find the coordinate in the vector that matches the highest point in the Convex Hull and set it at the start
    //vectors to do the swap
    vector<int> swapX;
    vector<int> swapY;

    for(int i=0; i<this->getVectorSize();i++)
    {
        if(this->highestXY[0] == this->convexHullX[i] && this->highestXY[1] ==this->convexHullY[i])
        {
            swapX.push_back(this->convexHullX[0]);          swapY.push_back( this->convexHullY[0]);
            this->convexHullX[i] = swapX[0];                this->convexHullY[i] = swapY[0];
            this->convexHullX[0] = this->highestXY[0];      this->convexHullY[0] =this->highestXY[1];

        }

    }

/*--------------------------------------------------------------------------------------------------------------------------*/

    //Sort the elements in the vectors to visualize them correctly
    float smallDist;
    float dist;
    int k =1;
    int l = 1;


    for(int i=0; i <this->getVectorSize();i++)
    {
        //find the smallDist to have something to compare to
        float distX = ((this->getConvexHullX(k)-this->getConvexHullX(i))*(this->getConvexHullX(k)-this->getConvexHullX(i)));
        float distY = ((this->getConvexHullY(k)-this->getConvexHullY(i))*(this->getConvexHullY(k)-this->getConvexHullY(i)));
        smallDist = sqrt(distX + distY);

        //do while the variable K is small than the Vector convexHull
        //find the smallest distance from element i in the vector to element k
        //do a swap after finding the smallest distance, between element K and element L in the vector convexHullX/Y
        do{

            distX = ((this->getConvexHullX(k)-this->getConvexHullX(i))*(this->getConvexHullX(k)-this->getConvexHullX(i)));
            distY = ((this->getConvexHullY(k)-this->getConvexHullY(i))*(this->getConvexHullY(k)-this->getConvexHullY(i)));
            dist = sqrt(distX + distY);

            if(dist < smallDist)
            {
                smallDist = dist;
                iter_swap(this->convexHullX.begin()+k, this->convexHullX.begin()+l);
                iter_swap(this->convexHullY.begin()+k, this->convexHullY.begin()+l);

            }
            k++;
        }while(k<this->getVectorSize());

        k = l+1;
        l++;

    }

/*-------------------------------------------------------------------------------------------------------------------------*/

    //Insert the highest coordinate into the back of the Convex Hull for the loop
      this->convexHullX.push_back(a.getX(index));
      this->convexHullY.push_back(a.getY(index));

    //Print the Convex Hull with the QuickHull algorithm
        cout<<"\nQuickHull:"<<endl;
        for(int i = 0; i < this->getVectorSize(); i++)
            {
                cout<<"QX: "<<this->convexHullX[i]<<" QY: "<<this->convexHullY[i]<<endl;
            }

}

void QuickHull::findHull(Punto2D S, int P, int Q)
{
    Punto2D S1, S2;
    int C;
    float dist1, dist2, res, farthest;
    farthest = 0;

    if(S.getPoint() ==  2)
    {
        return ;
    }


    //Calculate farthest point from segment PQ
    for( int i = 2; i<S.getPoint();i++)
    {
        dist1 = sqrt(((S.getX(i)-S.getX(P))*(S.getX(i)-S.getX(P)))+((S.getY(i)-S.getY(P))*(S.getY(i)-S.getY(P))));
        dist2 = sqrt(((S.getX(i)-S.getX(Q))*(S.getX(i)-S.getX(Q)))+((S.getY(i)-S.getY(Q))*(S.getY(i)-S.getY(Q))));
        res = dist1 + dist2;

        if(res>farthest)
        {
            farthest = res;
            C = i;
        }
    }

    //Save the farthest point into the Convex Hull
    this->convexHullX.push_back(S.getX(C));     this->convexHullY.push_back(S.getY(C));


    //Save the initial points of the the two new partitions S1 and S2
    S1.setX(S.getX(P));    S1.setY(S.getY(P));
    S1.setX(S.getX(C));    S1.setY(S.getY(C));

    S2.setX(S.getX(Q));    S2.setY(S.getY(Q));
    S2.setX(S.getX(C));    S2.setY(S.getY(C));

    int p1 = 2; int p2 =2;
    for(int i=0; i<S.getPoint(); i++)
    {
        if(isLeftOrRight(S, P, i, C) == 1)
        {
            S1.setX(S.getX(i));         //S1 has all points right of segment P to C
            S1.setY(S.getY(i));
            p1++;
        }
        else if(isLeftOrRight(S, C, i, Q) == 1)
        {
            S2.setX(S.getX(i));        //S2 has all points right of segment C to Q
            S2.setY(S.getY(i));
            p2++;
        }

    }

    //Set the number of points in the new partitions
    S1.setPoint(p1);    S2.setPoint(p2);


    //Find the rest of the Convex Hull Recursively
    findHull(S1, 0, 1);
    findHull(S2, 1, 0);


}



Punto2D QuickHull::copyConvexHull()
{
    Punto2D *a = new Punto2D;

    //Erase previous data in order to save new convexHull
    a->clearVector();

    //Set the Convex Hull obtained from GiftWrap Algorithm
    for(int i = 0; i<this->getVectorSize();i++)
    {
        a->setConvexHullX(this->getConvexHullX(i));
        a->setConvexHullY(this->getConvexHullY(i));
    }
    return *a;
}

int QuickHull::isLeftOrRight(Punto2D a, int m, int i , int o)
{
    int result;


    result = ((a.getY(i)-a.getY(m))*(a.getX(o)-a.getX(i)))-((a.getY(o)-a.getY(i))*(a.getX(i)-a.getX(m)));

    if(result == 0)
    {
        return 0;	//collinear
    }

    return  (result>0)? 1:2; //if greater than 0, clockwise, else counterclockwise

}



int QuickHull::getVectorSize()
{
    return this->convexHullX.size();

}

