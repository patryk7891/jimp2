//
// Created by mikolaj on 09.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H


#include <string>

namespace academia
{
    //klasę Student z polami id, first_name, last_name, program, year, gdzie wszystkie pola poza year są typu string, a pole year ma własny typ StudyYear.

    class StudyYear
    {
    public:
        StudyYear();
        StudyYear(int x);
        ~StudyYear();

        int study_year;

        void SetYear(int year);

    };

    class Student
    {
    public:
        Student();
        Student(std::string id, std::string firstname, std::string lastname, std::string program, StudyYear year);

        std::string id;
        std::string first_name;
        std::string last_name;
        std::string program;
        StudyYear year;


    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
