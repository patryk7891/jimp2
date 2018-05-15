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

        return result1!=v.end();

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
        std::transform(v.begin(), v.end(), std::back_inserter(vi), [](double x){return std::to_string(x);});
        return vi;
    }
//
    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key)
    {
        std::vector<std::string> vi;
        std::transform(v.begin(), v.end(), std::back_inserter(vi), [](std::pair<std::string, int> a) {return a.first;});
        auto result1 = std::find(vi.begin(), vi.end(), key);

        return result1!=vi.end();

    }
    std::set<std::string> Keys(const std::map<std::string, int> &m)
    {
        std::set<std::string> vi;
        std::transform(m.begin(), m.end(), std::inserter(vi, vi.begin()), [](std::pair<std::string, int> a) {return a.first;});
        return vi;
    }
    bool ContainsValue(const std::map<std::string, int> &v, int value)
    {
        std::vector<int> vi;
        std::transform(v.begin(), v.end(), std::back_inserter(vi), [](std::pair<std::string, int> a) {return a.second;});
        auto result1 = std::find(vi.begin(), vi.end(), value);

        return result1!=vi.end();
    }
    std::vector<int> Values(const std::map<std::string, int> &m)
    {
        std::vector<int> vi;
        std::transform(m.begin(), m.end(), std::back_inserter(vi), [](std::pair<std::string, int> a) {return a.second;});
        return vi;
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

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor)
    {
        std::map<std::string, int> a;
        std::transform(m.begin(), m.end(), std::inserter(a, a.begin()), [divisor](std::pair<std::string, int> a) {if(a.second%divisor==0){return a;};});

        return a;
    };

}