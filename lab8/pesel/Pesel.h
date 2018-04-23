//
// Created by mikolaj on 22.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>


namespace academia {


    class Pesel
    {
    public:
        Pesel();

        Pesel(const char *s);

        ~Pesel();

        void validatePESEL(const char *s);

    private:
        int pesel[11];
    };

    class AcademiaDataValidationError : public std::runtime_error
    {
    public:
        AcademiaDataValidationError(const std::string & message) : std::runtime_error(message){};

    };

    class InvalidPeselLength: public AcademiaDataValidationError {
    public:
        InvalidPeselLength() : AcademiaDataValidationError("Invalid Pesel Length"){};
        InvalidPeselLength(const std::string & pesel, int length) : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") length: " + std::to_string(length)){};
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError {
    public:
        InvalidPeselCharacter() : AcademiaDataValidationError("Invalid Pesel Character"){};
        InvalidPeselCharacter(const std::string & pesel) : AcademiaDataValidationError("Invalid PESEL("+ pesel +") character set"){};
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError {
    public:
        InvalidPeselChecksum() : AcademiaDataValidationError("Invalid Pesel Checksum"){};
        InvalidPeselChecksum(const std::string & pesel, int checksum) : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") checksum: " + std::to_string(checksum)){};
    };
}
#endif //JIMP_EXERCISES_PESEL_H
