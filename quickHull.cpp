#include "quickHull.h"

QuickHull::QuickHull()
{

}

int QuickHull::getQHullY(int value)
{
    return QHullY[value];
}

void QuickHull::setQHullY(int value)
{
    QHullY.push_back(value);
}

void QuickHull::setQHullX(int value)
{
    QHullX.push_back(value);

}

int QuickHull::getQHullX(int value)
{
    return QHullX[value];
}

int QuickHull::getVectorSize()
{
    return QHullX.size();

}

void QuickHull::QHull(Punto2D a)
{
    int pos=0;                            //
    for(int i=0;i<a.getPoint();i++)       //
    {                                     //
        if(a.getY(i)<a.getY(pos))         //obtener la posicion mas baja
        {                                 //
             pos = i;                     //
        }                                 //
    }                                     //

    this->QHullX.push_back(a.getX(pos));
    this->QHullY.push_back(a.getY(pos));

    pos=0;
    for(int i=0;i<a.getPoint();i++)       //
    {                                     //
        if(a.getY(i)>a.getY(pos))         //obtener la posicion mas alta
        {                                 //
             pos = i;                     //
        }                                 //
    }                                     //

    this->QHullX.push_back(a.getX(pos));
    this->QHullY.push_back(a.getY(pos));

    pos=0;
    for(int i=0;i<a.getPoint();i++)       //
    {                                     //
        if(a.getX(i)<a.getX(pos))         //obtener la posicion
        {                                 //mas a la izquierda
             pos = i;                     //
        }                                 //
    }

    this->QHullX.push_back(a.getX(pos));
    this->QHullY.push_back(a.getY(pos));


}

void QuickHull::pintar(QuickHull c)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(0,1,1);
            for(int i = 0; i < c.getVectorSize();i++)
            {
                glVertex2s(c.getQHullX(i),c.getQHullY(i)*(-1));

            }
}





