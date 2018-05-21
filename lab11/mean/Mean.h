//
// Created by mikolaj on 22.05.18.
//

#ifndef JIMP_EXERCISES_MEAN_H
#define JIMP_EXERCISES_MEAN_H

#include <vector>

template <class T>
auto Mean(std::vector<T> v)
{
    auto sum = T(); 
    for(auto a: v)
    {
        sum = sum + a; 
    }
    
    auto mean = sum/v.size(); 
    return mean; 
}


#endif //JIMP_EXERCISES_MEAN_H
