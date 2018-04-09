//
// Created by mikolaj on 09.04.18.
//

#include "Zipper.h"

namespace datastructures {


    std::vector<std::pair<std::string, int>> Zipper::zip(std::vector<std::string> v1, std::vector<int> v2)
    {

        std::vector<std::pair<std::string, int>> wektor;

        if(v1.size() <= v2.size())
        {
            int i=0;
           for(i; i< v1.size(); i++)
           {
               wektor.emplace_back(std::make_pair(v1[i], v2[i]));

           }
            for(i; i< v2.size(); i++)
            {
                wektor.emplace_back(std::make_pair("", v2[i]));

            }


        }
        else
        {
            int i=0;
            for(i; i< v2.size(); i++)
            {
                wektor.emplace_back(std::make_pair(v1[i], v2[i]));

            }
            for(i; i< v1.size(); i++)
            {
                wektor.emplace_back(std::make_pair(v1[i], 0));

            }

        }
        return wektor;
    };
}