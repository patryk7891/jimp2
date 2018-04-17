//
// Created by mikolaj on 16.04.18.
//



#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>
#include <memory>
#include <random>
#include <iostream>
using std::vector;
using ::std::default_random_engine;
using ::std::uniform_int_distribution;
using ::std::make_unique;
using ::std::unique_ptr;

/*
  [2 plusy] Zdefiniować metody wypełniania tablicy std::vector<int>:

    jednorone (zawsze ta sama wartość), z wartością domyślną 0
    z inkrementacją (uwzględniająca wartość początkową start i krok step, który ma wartość domyślną 1)
    za pomocą generatora liczb losowych
    z kwadratem indeksu (a*index^2+b), zarówno a i b mogą przyjąć domyślne wartości


 */

namespace arrays
{
    class ArrayFill
    {
    public:
        virtual int Value(int index) const;
    };

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };

    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(int value, int step=1) : value_{value}, step{step} {}
        virtual int Value(int index) const override;
    private:
        int value_;
        int step;
    };

    class SquaredFill : public ArrayFill {
    public:
        SquaredFill(int a=1, int b=0) :  a_{a}, b_{b} {}
        virtual int Value(int index) const override;
    private:
        int a_;
        int b_;
    };

    class RandomFill : public ArrayFill {
    public:
        RandomFill(unique_ptr<default_random_engine> generator, unique_ptr<uniform_int_distribution<int>> distribution)  :  gene{*generator}, distrib{*distribution} {}
        virtual int Value(int index) const override;
    private:

        uniform_int_distribution<int> distrib;
        default_random_engine gene;
    };


    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);
}


#endif //JIMP_EXERCISES_ARRAYFILL_H
