#include "quickHull.h"



QuickHull::QuickHull()
{

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

    //Insert the highest coordinate into the Convex Hull
    this->convexHullX.push_back(a.getX(index));    this->convexHullY.push_back(a.getY(index));

    //Save to HighestXY
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

    S1.setX(a.getX(index));     S1.setY(a.getY(index));
    S1.setX(a.getX(index2));    S1.setY(a.getY(index2));

    S2.setX(a.getX(index));     S2.setY(a.getY(index));
    S2.setX(a.getX(index2));    S2.setY(a.getY(index2));
    int p1 = 2; int p2 =2;
    for(int i=0; i<a.getPoint(); i++)
    {
        if(isLeft(a, index, i, index2) == 2)
        {
            S1.setX(a.getX(i));         //S1 has all points left of segment HighestXY to LowestXY
            S1.setY(a.getY(i));
            p1++;
        }
        else if(isLeft(a, index, i, index2) == 1)
        {
            S2.setX(a.getX(i));         //S2 has all points right of segment HighestXY to LowestXY
            S2.setY(a.getY(i));
            p2++;
        }

    }
    S1.setPoint(p1);    S2.setPoint(p2);

///* //para comprobar
for(int j=0; j<S1.getPoint();j++)
{
    cout<<"S1: "<<S1.getX(j)<<" "<<S1.getY(j)<<endl;
}

for(int j=0; j<S2.getPoint();j++)
{
    cout<<"S2: "<<S2.getX(j)<<" "<<S2.getY(j)<<endl;
}
//*/





    findHull(S1, 0, 1);
    findHull(S2, 0, 1);



        //Insert the lowest coordinate into the Convex Hull
        this->convexHullX.push_back(a.getX(index2));
        this->convexHullY.push_back(a.getY(index2));

        for(int i = 0; i < this->getVectorSize(); i++)
            {
                cout<<"QX: "<<this->convexHullX[i]<<" QY: "<<this->convexHullY[i]<<endl;
            }

}

void QuickHull::findHull(Punto2D S, int P, int Q)
{
    Punto2D S1, S2;
    int C;
    float dist1, dist2, res,farthest;
    farthest = 0;

    if(S.getPoint() <=  2)
    {
        return ;
    }


    //Calculate farthest point from segment PQ
    for( int i = 0; i<S.getPoint();i++)
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



    S1.setX(S.getX(P));    S1.setY(S.getY(P));
    S1.setX(S.getX(C));    S1.setY(S.getY(C));

    S2.setX(S.getX(C));    S2.setY(S.getY(C));
    S2.setX(S.getX(Q));    S2.setY(S.getY(Q));

    int p1 = 2; int p2 =2;
    for(int i=0; i<S.getPoint(); i++)
    {
        if(isLeft(S, P, i, C) == 1)
        {
            S1.setX(S.getX(i));         //S1 has all points right of segment P to C
            S1.setY(S.getY(i));
            p1++;
        }

    }

    for(int i=0; i<S.getPoint(); i++)
    {
        if(isLeft(S, C, i, Q) == 1)
        {
            S2.setX(S.getX(i));         //S2 has all points right of segment C to Q
            S2.setY(S.getY(i));
            p2++;
        }

    }
    S1.setPoint(p1);    S2.setPoint(p2);

    for(int j=0; j<S1.getPoint();j++)
    {
        cout<<"S1: "<<S1.getX(j)<<" "<<S1.getY(j)<<endl;
    }

    for(int j=0; j<S2.getPoint();j++)
    {
        cout<<"S2: "<<S2.getX(j)<<" "<<S2.getY(j)<<endl;
    }


    findHull(S1, P, Q);
    findHull(S2, Q, P);


/*
    From the given set of points in Sk, find the farthest point, Say C, from segment PQ,
            Add point C to convex Hull at the location between PQ
            Three points p,q, and C partition the remaining points of Sk into 3 subsets s0,s1.s2
            where s0 are the points inside the triangle, s1 are points to the right side of the oriented line from P to C
            and s2 are points on the right side of the oriented line from C to Q

            FindHull(S1, P, C);
            FindHull(S2, C, Q);
*/
}

int QuickHull::isLeft(Punto2D a, int m, int i , int o)
{
    int result;

    //result = ((a.getY(i)-this->gethighestXY(m+1))*(this->getlowestXY(o)-a.getX(i)))-((this->getlowestXY(o+1)-a.getY(i))*(a.getX(i)-this->gethighestXY(m)));
    result = ((a.getY(i)-a.getY(m))*(a.getX(o)-a.getX(i)))-((a.getY(o)-a.getY(i))*(a.getX(i)-a.getX(m)));
   // cout<<result;
    if(result == 0)
    {
        return 0;	//collinear
    }

    return  (result>0)? 1:2; //if greater than 0, clockwise, else counterclockwise

}

int QuickHull::isRight(Punto2D S, int P, int Q)
{

}

int QuickHull::getVectorSize()
{
    return this->convexHullX.size();

}

