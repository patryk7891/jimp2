//
// Created by patryk on 24.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H


#include <string>
#include <experimental/optional>
#include <iostream>
#include <vector>
#include <map>

using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::std::literals::operator""s;
using ::std::experimental::optional;

namespace nets
{
    class JsonValue
    {
    public:
        JsonValue();
        JsonValue(int number_);

        JsonValue(string name);
        JsonValue(double value_);
        JsonValue(bool flag);
        JsonValue(map<string, JsonValue> jakas_mapa);
        JsonValue(vector<JsonValue> some_vector);
        ~JsonValue();
        optional<JsonValue> ValueByName(const string &name) const;
        string ToString() const;

    private:
        optional<int> number;
        optional<double> value;
        optional<string> name;
        optional<bool> flag;
        optional<map<string, JsonValue>> jakas_mapa;
        optional<vector<JsonValue>> jakis_wektor;


    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
