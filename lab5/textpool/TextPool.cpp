//
// Created by mikolaj on 08.04.18.
//

#include "TextPool.h"


namespace pool
{
    TextPool::TextPool(){};

    TextPool::TextPool(TextPool &&xxx)
    {
        swap(string_viev_set, xxx.string_viev_set);
    }


    TextPool& TextPool::operator=(TextPool &&xxx)
    {
        if (this == &xxx) {
            return *this;
        }
        string_viev_set.clear();

        swap(string_viev_set, xxx.string_viev_set);
    }

    TextPool::~TextPool()
    {
        string_viev_set.clear();
    };


    TextPool::TextPool(const std::initializer_list<string_view> &xxx) {

        for (auto i : xxx)
        {
            string_viev_set.insert(i);
        }
    }

    std::experimental::string_view TextPool::Intern(const std::string &str)
    {
        for(auto i : string_viev_set)
        {
            if(i==str)
            {
                return i;
            }
        }

        string_viev_set.insert(str);
        return str;
    }

    size_t TextPool::StoredStringCount() const
    {
        return string_viev_set.size();
    }

}