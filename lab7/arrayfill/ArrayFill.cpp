//
// Created by mikolaj on 16.04.18.
//

#include "ArrayFill.h"

namespace arrays
{

    int ArrayFill::Value(int index) const
    {
        return 0;
    }

    int UniformFill::Value(int index) const {
        return value_;
    }

    int IncrementalFill::Value(int index) const {
        return value_ + step*index;
    }

    int SquaredFill::Value(int index) const {

        return ((a_*index*index)+b_);

    }

    int RandomFill::Value(int index) const {
        auto dice = std::bind ( distrib, gene );
        int wisdom = dice();
        return wisdom;

    }

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v)
    {
        v->clear();
        v->reserve(size);

        for (size_t i = 0; i < size; i++)
        {
            v->emplace_back(filler.Value(i));
        }
    }
}