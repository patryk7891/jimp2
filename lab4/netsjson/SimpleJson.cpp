#include "SimpleJson.h"

namespace nets {
    JsonValue::JsonValue(){
        cout<<"Brak parametru"<<endl;
    }
    JsonValue::JsonValue(int number_) {
        number = std::experimental::make_optional(number_);
    }
    JsonValue::JsonValue(double value_) {
        value = std::experimental::make_optional(value_);
    }
    JsonValue::JsonValue(string name_) {
        name = std::experimental::make_optional(name_);
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
    if (number) {
        if (*number == 0) return ""s;
        else return std::to_string(*number);
    }
    if (value)  {
        return std::to_string(*value).substr(0,std::to_string(*value).length()-4);}
    if (flag){
        if(*flag) return "true";
        else return "false";
    }
    if(name){
        string tmp=*name;
        unsigned long len=(*name).length();
        unsigned long index=0;
        for (int i=0;i<len;i++){
            if(((*name)[i]=='\"') or (*name)[i]=='\\'){
                tmp.insert(i+index,"\\");
                index++;
            }
        }
        return "\""+tmp+"\""s;
    }
    if(jakas_mapa){
        string map_str="{"s;
        for (auto p:*jakas_mapa){
            string tmp=p.first;
            unsigned long len=tmp.length();
            unsigned long index=0;
            for (int j=0;j<len;j++){
                if(((p.first)[j]=='\"') or (p.first)[j]=='\\'){
                    tmp.insert(j+index,"\\");
                    index++;
                }
            }
            map_str += "\"" + tmp + "\": ";
            map_str += (p.second.ToString() +", ");
        }
        map_str = map_str.substr(0,map_str.length()-2);
        map_str += "}"s;
        return map_str;
    }
    if(jakis_wektor){
        string tmp = "["s;
        for (auto p : *jakis_wektor) {
            tmp+= (p.ToString() +", ");
        }
        tmp =  tmp.substr(0, tmp.length()-2);
        tmp += "]"s;
        return tmp;
    }
    return ""s;
    }


optional<JsonValue> JsonValue::ValueByName(const string &namee) const {
    if (jakas_mapa) {
        for (auto p : *jakas_mapa) {
            if (p.first == namee)
                return std::experimental::make_optional(p.second);
        }
    }
    return {};
}

}

