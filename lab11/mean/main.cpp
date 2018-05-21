//
// Created by mikolaj on 22.05.18.
//
#include "Mean.h"
#include <iostream>


int main()
{
    std::vector <int> v = {1,2,3,4,5};
    std::cout << Mean(v)<<std::endl;

    std::vector <double> v1 = {1.3,2.2,3.4,4.6,5.5};
    std::cout << Mean(v1)<<std::endl;

};