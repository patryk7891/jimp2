//
// Created by mikolaj on 09.04.18.
//

#include "StudentRepository.h"

namespace academia
{

    StudyYear::StudyYear()
    {
        study_year = 1;
    };

    StudyYear::StudyYear(int x)
    {
        study_year = x;
    }

    StudyYear::~StudyYear() {}

    void StudyYear::SetYear(int year)
    {
        study_year = year;
    }


    Student::Student(std::string id, std::string firstname, std::string lastname, std::string program, StudyYear year)
    {

    }


}