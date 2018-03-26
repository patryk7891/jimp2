#include "SimpleJson.h"

namespace nets {
    JsonValue::JsonValue(){
        cout<<"Brak parametru"<<endl;
    }
    JsonValue::JsonValue(int number_) {
        liczba = std::experimental::make_optional(number_);
    }
    JsonValue::JsonValue(double value_) {
        value = std::experimental::make_optional(value_);
    }
    JsonValue::JsonValue(string name_) {
        nazwa = std::experimental::make_optional(name_);
    }
    JsonValue::JsonValue(bool flag_) {
        flag = std::experimental::make_optional(flag_);
    }
    JsonValue::JsonValue(vector<JsonValue> some_vector_) {
        jakis_wektor = std::experimental::make_optional(some_vector_);
    }
    JsonValue::JsonValue(map<string,JsonValue> some_map_) {
        jakas_mapa = std::experimental::make_optional(some_map_);
    }
    JsonValue::~JsonValue(){}






    string JsonValue::ToString() const {
    if (liczba) {
        if (*liczba == 0) return ""s;
        else return std::to_string(*liczba);
    }



    if (value)  { return std::to_string(*value).substr(0,std::to_string(*value).length()-4);}

    if (flag){
        if(*flag) return "true";
        else return "false";}


    if(nazwa){
        string napis=*nazwa;
        unsigned long dlugosc=(*nazwa).length(), indeks=0;
        for (int i=0;i<dlugosc;i++){
            if(((*nazwa)[i]=='\"') or (*nazwa)[i]=='\\'){
                napis.insert(i+indeks,"\\");
                indeks++;
            }
        }
        return "\""+napis+"\""s;
    }
    if(jakas_mapa){
        string map_str="{"s;
        for (auto p:*jakas_mapa){
            string tymczasowa=p.first;
            unsigned long dlugosc=tymczasowa.length(),indeks=0;
            for (int i=0;i<dlugosc;i++){
                if(((p.first)[i]=='\"') or (p.first)[i]=='\\'){
                    tymczasowa.insert(i+indeks,"\\");
                    indeks++;
                }
            }
            map_str += "\"" + tymczasowa + "\": ";
            map_str += (p.second.ToString() +", ");
        }
        map_str = map_str.substr(0,map_str.length()-2);
        map_str += "}"s;
        return map_str;
    }
    if(jakis_wektor){
        string temporary = "["s;
        for (auto p : *jakis_wektor) {
            temporary+= (p.ToString() +", ");
        }
        temporary =  temporary.substr(0, temporary.length()-2);
        temporary += "]"s;
        return temporary;
    }
    return ""s;
    }


optional<JsonValue> JsonValue::ValueByName(const string &slowo) const {
    if (jakas_mapa) {
        for (auto p : *jakas_mapa) {
            if (p.first == slowo)
                return std::experimental::make_optional(p.second);
        }
    }
}

}



