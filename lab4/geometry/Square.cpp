//
// Created by mikolaj on 19.03.18.
//

#include "Square.h"
#include <cmath>
#include <ostream>




    Square::Square(Point p11, Point p21, Point p31, Point p41) {
        p1 = p11;
        p2 = p21;
        p3 = p31;
        p4 = p41;
    }

    double Square::Circumference() {
        return (sqrt(pow(std::abs(p1->x_ - p2->x_), 2) + pow(std::abs(p1->y_ - p2->y_), 2))) * 4.0;
    }

    double Square::Area() {
        return pow(std::abs(p1->x_ - p2->x_), 2) + pow(std::abs(p1->y_ - p2->y_), 2) * sqrt(2.0);
    }

