//
// Created by mikolaj on 15.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <vector>
#include <initializer_list>
#include <set>
#include <utility>
#include <algorithm>
#include <list>

namespace datastructures
{
    class Counts
    {
    public:
        friend class WordCounter;
        Counts();
        Counts(int x);
        ~Counts();


        Counts &operator++();

        bool operator==(Counts another_count) const;

        bool operator<(Counts another_count) const;

        bool operator>(Counts another_count) const;

    private:
        int count;
    };

    class Word
    {
    public:
        friend class WordCounter;
        Word();
        Word(std::string x);
        ~Word();

        bool operator<(Word wo) const ;

        bool operator>(Word wo) const ;

        bool operator==(Word wo) const ;

    private:

        std::string word;
    };

    class WordCounter
    {
    public:
        WordCounter();
        WordCounter(std::initializer_list<Word> list);

        int operator[](std::string id);

        int DistinctWords();
        int TotalWords();
        std::set<Word> Words();

    private:
        std:: vector<std::pair<Word, Counts>> counter;
        int total;
        int distinct;
    };
}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
