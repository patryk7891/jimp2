//
// Created by mikolaj on 05.03.18.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H

using namespace std;


#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>


std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary);


#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
