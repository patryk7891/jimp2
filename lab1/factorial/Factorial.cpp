//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
    if(value>=13)
    {
        return 0;
    }

    if(value==0 || value==1)
    {
        return 1;
    }
    else if(value>1)
    {
        return value*factorial(value-1);
    }
    else if(value<0)
    {
        return value*factorial(value+1);
    }
    //std::cout<<"sprawdzenie"<<std::endl;
    return 0;
  return 0;
}
