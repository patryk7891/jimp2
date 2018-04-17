//
// Created by mikolaj on 17.04.18.
//

#ifndef JIMP_EXERCISES_KOLOKULA_H
#define JIMP_EXERCISES_KOLOKULA_H

/*
W klasie Kolo powinny znaleźć się następujące pola i metody:

double x, y, r - określające odpowiednio współrzędne środka koła i jego promień.
double pole() - obliczająca pole koła
*/

class Kolo
{
public:
    Kolo();
    Kolo(double x, double y, double r);
    ~Kolo();

    double pole();

    double x_;
    double y_;
    double r_;
};

class Kula: public Kolo
{
public:
    Kula();
    Kula(double x_, double y_, double r_, double z_);
    ~Kula();

    double pole();
    double pole_przekroju();

    double z_;
};



#endif //JIMP_EXERCISES_KOLOKULA_H
