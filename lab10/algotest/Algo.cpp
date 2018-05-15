//
// Created by mikolaj on 14.05.18.
//

#include <bits/unique_ptr.h>
#include "Algo.h"
#include <memory>


namespace algo
{
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out)
    {
        out->resize((unsigned long)n_elements);
        std::copy_n(v.begin(), n_elements, out->begin());
    }

    bool Contains(const std::vector<int> &v, int element)
    {
        auto result1 = std::find(v.begin(), v.end(), element);

        if(result1 != v.end())
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    void InitializeWith(int initial_value, std::vector<int> *v)
    {
        std::fill(v->begin(), v->end(), initial_value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value)
    {
        std::vector<int> v;
        v.resize((unsigned long) length);
        std::fill(v.begin(), v.end(), initial_value);

        return v;
    }

    std::vector<std::string> MapToString(const std::vector<double> &v)
    {
        std::vector<std::string> vi;
        for(auto a : v)
        {
            vi.emplace_back(std::to_string(a));
        }
        return vi;
    }
//
    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key)
    {
        for (auto a : v)
        {
            if (a.first==key)
            {
                return true;
            }
        }
        return false;
    }
    std::set<std::string> Keys(const std::map<std::string, int> &m)
    {
        std::set<std::string> s;
        for (auto a : m)
        {
            s.emplace(a.first);
        }
        return s;
    }
    bool ContainsValue(const std::map<std::string, int> &v, int value)
    {
        for (auto a : v)
        {
            if (a.second==value)
            {
                return true;
            }
        }
        return false;
    }
    std::vector<int> Values(const std::map<std::string, int> &m)
    {
        std::vector<int> s;
        for (auto a : m)
        {
            s.emplace_back(a.second);
        }
        return s;
    }

    void SortInPlace(std::vector<int> *v)
    {
        std::stable_sort(v->begin(), v->end());
    }

    std::vector<int> Sort(const std::vector<int> &v)
    {
        std::vector<int> ret = v;
        std::sort(ret.begin(), ret.end());
        return ret;
    }


    int Sum(const std::vector<int> &v)
    {
        int sum = std::accumulate(v.begin(), v.end(), 0);
        return sum;
    }
    int Product(const std::vector<int> &v)
    {
        int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
        return product;
    }


    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m,int divisor)
    {

    };
    
    


}