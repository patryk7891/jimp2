//
// Created by mikolaj on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H


#include <string>
#include <memory>
#include <Serialization.h>
#include <vector>
#include <ostream>
#include <sstream>
#include <iostream>
#include <experimental/optional>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stringstream;
using std::reference_wrapper;


namespace academia
{

    class Serializable;

    class Serializer {
    public:
        explicit Serializer(std::ostream *out);
        Serializer()= default;

        virtual void IntegerField(const std::string &field_name, int value){
            int_val = value;
        };

        virtual void DoubleField(const std::string &field_name, double value){
            double_val = value;
        };

        virtual void StringField(const std::string &field_name, const std::string &value)
        {
            string_val = value;
        };

        virtual void BooleanField(const std::string &field_name, bool value)
        {
            boolean_val = value;
        };

        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value){};

        virtual void ArrayField(const std::string &field_name,
                                const std::vector <std::reference_wrapper<const academia::Serializable>> &value){};

        virtual void Header(const std::string &object_name){
            header_val = object_name;
        };

        virtual void Footer(const std::string &object_name)
        {
            footer_val = object_name;
        };


        int int_val;
        double double_val;
        std::string string_val;
        bool boolean_val;
        std::string header_val;
        std::string footer_val;

        std::ostream *out;

    };

    class Serializable
    {
    public:
        virtual void Serialize(Serializer*)const=0;
    };


    class Room : public Serializable
    {
    public:

        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        Room(int num, std::string name, Type type);

        void Serialize(Serializer *)const;


        int num_;
        std::string name_;
        Type type_;


    };

    class Building : public Serializable
    {
    public:
        Building(int number, std::string nam, std::vector<Room> rom);
        void Serialize(Serializer *)const ;
        bool operator==(const Building otherBuilding) const;
        int Id()const ;
        int number_;
        std::string name_;
        std::vector<Room> room_;
    };

    class JsonSerializer : public Serializer
    {
    public:
        JsonSerializer(std::stringstream *out){this->out = out;}
        void IntegerField(const std::string &field_name, int value) override {
            *out << "\"" << field_name << "\": " << std::to_string(value);
            len=1;
        };

        void DoubleField(const std::string &field_name, double value) override{
            *out << std::to_string(value);
            len=1;
        };

        void StringField(const std::string &field_name, const std::string &value) override
        {
            *out << ", \"" << field_name << "\": \"" << value << "\"" ;
            len=1;
        };

        void BooleanField(const std::string &field_name, bool value)override
        {
            *out << std::to_string(value);
            len=1;
        };

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override{};

        void ArrayField(const std::string &field_name,
                                const std::vector <std::reference_wrapper<const academia::Serializable>> &value)override{
            if (len!=1)
            {
                *out << "\"" << field_name << "\": [";
            }
            else {
                *out << ", \"" << field_name << "\": [";
            }
            if (value.size() == 0) {
                *out << "]";
            } else {
                int i=1;
                for (const Serializable &el : value) {
                    el.Serialize(this);
                    if (i < value.size())
                        *out<< ", ";
                    i++;
                }

                *out << "]";
            }
        };

        void Header(const std::string &object_name)override{
            *out << "{";
        };

        void Footer(const std::string &object_name)override
        {
            *out << "}";
        };


        std::stringstream *out;
        int len;
    };

    class XmlSerializer : public Serializer
    {
    public:
        XmlSerializer(std::stringstream *out){this->out = out;}
        void IntegerField(const std::string &field_name, int value) override {
            *out << "<" << field_name <<">"<< std::to_string(value) <<"<\\" << field_name << ">";
        };

        void DoubleField(const std::string &field_name, double value) override{
            *out << std::to_string(value);
        };

        void StringField(const std::string &field_name, const std::string &value) override
        {
            *out << "<" << field_name <<">"<< value <<"<\\" << field_name << ">";
        };

        void BooleanField(const std::string &field_name, bool value)override
        {
            *out << std::to_string(value);
        };

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override{};

        void ArrayField(const std::string &field_name,
                        const std::vector <std::reference_wrapper<const academia::Serializable>> &value)override{
            *out << "<" << field_name <<">";
            if (value.size() != 0)
            {
                int i=1;
                for (const Serializable &el : value) {
                    el.Serialize(this);
                    if (i < value.size())
                    i++;
                }
            }
            *out << "<\\" << field_name <<">";
        };

        void Header(const std::string &object_name)override{
            *out << "<"<<object_name<<">";
        };

        void Footer(const std::string &object_name)override
        {
            *out << "<\\"<<object_name<<">";
        };


        std::stringstream *out;
    };

    class BuildingRepository {
    public:
        BuildingRepository(const std::initializer_list<Building> &buildings) : Vector{buildings}{};
        void Add(Building new_building);
        void StoreAll(Serializer *serializer) const;
        std::vector< std::reference_wrapper<const Serializable> > getBuildings() const;
        std::experimental::optional<Building> operator[](int buildingId) const;
    private:
        std::vector<Building> Vector;
    };

}

#endif //JIMP_EXERCISES_SERIALIZATION_H