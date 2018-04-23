//
// Created by mikolaj on 22.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>


namespace academia
{
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
        AcademiaDataValidationError(const std::string & info) : std::runtime_error(info){};

    };

    class InvalidPeselLength: public AcademiaDataValidationError {
    public:
        InvalidPeselLength() : AcademiaDataValidationError("Invalid Pesel Length"){};
        InvalidPeselLength(const std::string & nrpesel, int length) : AcademiaDataValidationError("Invalid PESEL(" + nrpesel + ") length: " + std::to_string(length)){};
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError {
    public:
        InvalidPeselCharacter() : AcademiaDataValidationError("Invalid Pesel Character"){};
        InvalidPeselCharacter(const std::string & nrpesel) : AcademiaDataValidationError("Invalid PESEL("+ nrpesel +") character set"){};
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError {
    public:
        InvalidPeselChecksum() : AcademiaDataValidationError("Invalid Pesel Checksum"){};
        InvalidPeselChecksum(const std::string & nrpesel, int checksum) : AcademiaDataValidationError("Invalid PESEL(" + nrpesel + ") checksum: " + std::to_string(checksum)){};
    };
}
#endif //JIMP_EXERCISES_PESEL_H
