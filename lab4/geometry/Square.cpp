//
// Created by mikolaj on 19.03.18.
//

#include "Square.h"
#include <cmath>
#include <ostream>

namespace geometry {

    Square::Square(Point p11, Point p21, Point p31, Point p41) {
        p1 = p11;
        p2 = p21;
        p3 = p31;
        p4 = p41;
    }

    double Square::Circumference() {
        double a = p1.Distance(p2);
        if(a<=0 || a!= p3.Distance(p4))
        {
            return 0;
        }
        return a * 4;
    }

    double Square::Area() {
        double a = p1.Distance(p2);
        if(a<=0 || a!= p3.Distance(p4))
        {
            return 0;
        }
        return a * a;
    }

}