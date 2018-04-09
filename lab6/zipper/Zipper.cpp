//
// Created by mikolaj on 09.04.18.
//

#include "Zipper.h"

namespace datastructures {


    std::vector<std::pair<std::string, int>> Zipper::zip(std::vector<std::string> v1, std::vector<int> v2) {
        std::vector<std::pair<std::string, int>> wektor;
        wektor.emplace_back(std::make_pair(v1[0], v2[0]));

        return wektor;
    };
}