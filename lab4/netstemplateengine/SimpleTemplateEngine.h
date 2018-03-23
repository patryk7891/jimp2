//
// Created by mikolaj on 23.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <iostream>

namespace nets
{
    class View{
    public:
        std::string text;

        View(std::string szablon);
        ~View();

        std::string Render(const std::unordered_map<std::string, std::string> &model) const;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
