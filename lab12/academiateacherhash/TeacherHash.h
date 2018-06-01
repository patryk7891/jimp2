//
// Created by mikolaj on 01.06.18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>
#include <functional>

namespace academia {
    class TeacherId{
    public:
        int id;
        TeacherId();
        TeacherId(int id);
        ~TeacherId();
        operator int() const
        {
            return this->id;
        }
    };
    class Teacher{
    public:
        TeacherId pole;
        std::string imie;
        std::string katedra;
        Teacher();
        Teacher(TeacherId pole, std::string imie, std::string katedra);
        ~Teacher();
        TeacherId Id();
        std::string Name();
        std::string Department();
        bool operator==(const Teacher &x) const;
        bool operator!=(const Teacher &x) const;

    };

    class TeacherHash{
    public:
        size_t operator()(const Teacher &x)const{return std::hash<int>()(x.pole.id)+std::hash<std::string>()(x.katedra) +std::hash<std::string>()(x.imie) ;}
    };
}


#endif //JIMP_EXERCISES_TEACHERHASH_H
