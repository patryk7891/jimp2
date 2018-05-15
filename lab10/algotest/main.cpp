//
// Created by mikolaj on 14.05.18.
//

#include "Algo.h"


int main()
{
    std::vector<int> v1{1,2,3,7,5};
    const std::vector<int> v2 {1,2,3,7,5};
    std::vector<int> *p = &v1;
    algo::SortInPlace(p);
    for(auto element : v1)
    {
        std::cout<<element<<" ";
    }
    std::cout<<std::endl;

    int suma = algo::Sum(v2);
    std::cout<<suma <<" jest suma"<< std::endl;
    int produkt = algo::Product(v2);
    std::cout<<produkt <<" jest produkt"<< std::endl;

    std::vector<int> a = algo::Sort(v2);
    for(auto element : a)
    {
        std::cout<<element<<" ";
    }
    std::cout<<std::endl;
}