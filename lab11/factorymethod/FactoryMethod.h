//
// Created by mikolaj on 21.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <vector>

namespace factoryMethod
{
    template<class T>
    T Create()
    {
        return T();
    }

    class MyType
    {
    public:
        std::string SayHello() const;
    };
}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
