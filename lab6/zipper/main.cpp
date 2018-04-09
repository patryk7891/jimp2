//
// Created by mikolaj on 09.04.18.
//

#include "Zipper.h"

int foo(const std::vector<std::string> &v1, const std::vector<int> &v2) {
    for (const std::pair<std::string,int> &p : Zipper::zip(v1,v2)) {
        if (p.first == "elo") {
            return p.second+4;
        }
    }
    return 0;
}