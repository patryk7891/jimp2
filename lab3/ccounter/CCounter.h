//
// Created by mikolaj on 11.03.18.
//

#ifndef JIMP_EXERCISES_CCOUNTER_H
#define JIMP_EXERCISES_CCOUNTER_H

#include <string>
#include <memory>
#include <map>
#include <vector>


namespace ccounter
{
    struct Counter
    {
        std::pair<std::vector<std::string>, std::map<std::string, int>> couple;
    };

    std::unique_ptr<Counter> Init();

    void Inc(std::string key, std::unique_ptr<Counter> *counter);

    int Counts(const std::unique_ptr<Counter> &counter, std::string key);

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter);
}

#endif //JIMP_EXERCISES_CCOUNTER_H
