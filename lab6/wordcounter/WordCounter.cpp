//
// Created by mikolaj on 15.04.18.
//

#include "WordCounter.h"


namespace datastructures
{
    Counts::Counts()
    {
        count = 0;
    }
    Counts::Counts(int x)
    {
        count = x;
    }
    Counts::~Counts(){};

    Word::Word()
    {
        word = "";
    }
    Word::Word(std::string x)
    {
        word = x;
    }
    Word::~Word(){}

    Counts &Counts::operator++()
    {
        this->count = count + 1;
        return *this;
    }

    bool Counts::operator==(Counts another_count) const
    {
        return this->count == another_count.count;
    }

    bool Counts::operator<(Counts another_count) const
    {
        return this->count < another_count.count;
    }

    bool Counts::operator>(Counts another_count) const
    {
        return this->count > another_count.count;
    }

    bool Word::operator<(Word wo) const {
        return this->word < wo.word;
    }

    bool Word::operator>(Word wo) const {
        return this->word > wo.word;
    }

    bool Word::operator==(Word wo) const {
        return this->word == wo.word;
    }

    int WordCounter::operator[](std::string w1)
    {
        for (auto iter : counter)
        {
            if (iter.first.word == w1)
            {
                return iter.second.count;
            }
        }
        return 0;
    }

    WordCounter::WordCounter()
    {
        total = 0;
        distinct = 0;
    }

    WordCounter::WordCounter(std::initializer_list<Word> list)
    {
        total = 0;
        distinct = 0;
        bool a;
        for (auto i : list)
        {
            a=true;
            for(auto j: counter)
            {
                if(j.first.word == i.word)
                {
                    total++;
                    ++find(counter.begin(),counter.end(), j)->second;
                    a=false;

                }
            }

            if (a)
            {
                total++;
                distinct++;
                Counts c1{1};
                std::pair<Word, Counts> p1 = std::make_pair(i, c1);
                counter.emplace_back(p1);
            }
        }
    }

    int WordCounter::DistinctWords()
    {
        return distinct;
    }
    int WordCounter::TotalWords()
    {
        return total;
    }

    std::set<Word> WordCounter::Words()
    {
        std::list<Word> lista;

        for(auto i: counter)
        {
            lista.emplace_back(i.first);
        }

        lista.sort();

        std::set<Word> wor = {};

        for(auto j: lista)
        {
            wor.insert(j);
        }

        return wor;
    }
}
