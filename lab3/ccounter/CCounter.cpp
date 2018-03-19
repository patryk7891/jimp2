//
// Created by mikolaj on 11.03.18.
//

#include "CCounter.h"


namespace ccounter
{
    std::unique_ptr<Counter> Init()
    {
        std::unique_ptr<Counter> licznik = std::make_unique<Counter>();
        return licznik;
    }

    void Inc(std::string key, std::unique_ptr<Counter> *counter)
    {
        auto k = counter->get()->mapa.find(key);

        if(k != counter->get()->mapa.end())
        {
            k->second++;
        }

        else
        {
            counter->get()->mapa.emplace_hint(k, key, 1);
        }
    }

    int Counts(const std::unique_ptr<Counter> &counter, std::string key)
    {
        auto k = counter->mapa.find(key);

        if (k != counter->mapa.end())
        {
            return k->second;
        }

        return 0;
    }

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter)
    {
        auto k = counter->get()->mapa.find(key);
        k->second = value;
    }
}