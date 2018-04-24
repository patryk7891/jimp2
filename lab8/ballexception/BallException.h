//
// Created by mikolaj on 22.04.18.
//

#ifndef JIMP_EXERCISES_BALLEXCEPTION_H
#define JIMP_EXERCISES_BALLEXCEPTION_H

#include <iostream>
using namespace std;

class CircleException{
    // Oznacza ze nie mozna wyrysowac kola
};

class BallException : public CircleException{
    // Oznacza ze nie mozna wyrysowac kuli
};

void drawBall();


#endif //JIMP_EXERCISES_BALLEXCEPTION_H
