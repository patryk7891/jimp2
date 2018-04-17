//
// Created by mikolaj on 17.04.18.
//

#include "KoloKula.h"


Kolo::Kolo()
{
    x_= 0;
    y_= 0;
    r_= 0;
}

Kolo::Kolo(double x, double y, double r)
{
    x_=x;
    y_=y;
    r_=r;
}

Kolo::~Kolo(){}

double Kolo::pole()
{
    return 3.14*r_*r_;
}

double Kula::pole()
{
    return 4*Kolo::pole();
}

double Kula::pole_przekroju()
{
    return Kolo::pole();
}

Kula::Kula()
{
    x_= 0;
    y_= 0;
    r_= 0;
    z_= 0;
}

Kula::Kula(double x, double y, double r, double z)
{
    x_=x;
    y_=y;
    r_=r;
    z_=z;
}

Kula::~Kula(){}