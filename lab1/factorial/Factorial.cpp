//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

bool OutOfRange(int value);

int Factorial(int value) {
    if(OutOfRange(value))
    {
        return 0;
    }

    if(value==0 || value==1)
    {
        return 1;
    }
    else if(value>1)
    {
        return value* Factorial(value - 1);
    }
    else if(value<0)
    {
        return value* Factorial(value + 1);
    }
    return 0;

}

bool OutOfRange(int value) { return value >= 13 || value <= -13; }
