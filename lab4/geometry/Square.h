//
// Created by mikolaj on 19.03.18.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H
#include <cstdlib>
#include "Point.h"

namespace geometry {
    class Square {
    public:
        Point p1;
        Point p2;
        Point p3;
        Point p4;

        Square(Point p11, Point p21, Point p31, Point p41);

        double Circumference();

        double Area();

    };
}

#endif //JIMP_EXERCISES_SQUARE_H
