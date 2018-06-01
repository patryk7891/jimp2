//
// Created by mikolaj on 01.06.18.
//

#include "TeacherHash.h"


namespace academia {
    TeacherId::TeacherId(){};
    TeacherId::TeacherId(int id){
        this->id = id;
    }
    TeacherId::~TeacherId(){};
    Teacher::Teacher(){};
    Teacher::Teacher(TeacherId pole, std::string imie, std::string katedra){
        this->pole = pole;
        this->imie = imie;
        this->katedra = katedra;
    };
    Teacher::~Teacher(){
        this->pole = TeacherId(0);
        this->imie = "";
        this->katedra = "";
    };
    TeacherId Teacher::Id(){
        return this->pole;
    };
    std::string Teacher::Name(){
        return this->imie;
    };
    std::string Teacher::Department(){
        return this->katedra;
    };

    bool Teacher::operator==(const Teacher &x)const {return (this->katedra==x.katedra && this->imie == x.imie && this->pole ==x.pole);};
    bool Teacher::operator!=(const Teacher &x)const {return (this->katedra!=x.katedra || this->imie != x.imie || this->pole !=x.pole);};
}