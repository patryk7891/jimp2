//
// Created by mikolaj on 09.04.18.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

#include <string>
#include <vector>
#include <cstdlib>

namespace datastructures {
    class Zipper {
    public:
        static std::vector<std::pair<std::string, int>> zip(std::vector<std::string>, std::vector<int>);

    };
}

#endif //JIMP_EXERCISES_ZIPPER_H
