//
// Created by mikolaj on 08.04.18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H


#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>


using std::experimental::string_view;

namespace pool
{
    class TextPool
    {
    public:

        //2. konstruktor przenoszący
        TextPool(TextPool &&xxx);

        //4. operator przypisania przenoszący
        TextPool &operator=(TextPool &&xxx);

        //5. Destruktor
        ~TextPool();

        //Domyslny konstruktor
        TextPool();

        //konstruktor z listą inicjalizacyjną
        TextPool(const std::initializer_list<string_view> &xxx);

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;

    private:
        std::set<string_view> string_viev_set;


    };
}


#endif //JIMP_EXERCISES_TEXTPOOL_H
