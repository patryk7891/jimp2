//
// Created by mikolaj on 22.04.18.
//

#include "Pesel.h"


namespace academia
{

    Pesel::Pesel() {};

    Pesel::Pesel(const char *s)
    {
        validatePESEL(s);
    };

    Pesel::~Pesel() {};

    void Pesel::validatePESEL(const char *y)
    {
        for(int i = 0;i<12 ; i++)
        {
            if(i < 11 && y[i] == '\0')
            {
                throw InvalidPeselLength();
            }

            if (i == 11 && y[i] == '\0')
            {
                break;
            }

            else if(i == 11 && y[i] != '\0')
            {
                throw InvalidPeselLength();
            }
        }

        for(int i = 0; i < 11; i++)
        {
            if((y[i]) < '0' || (y[i]) > '9')
            {
                throw InvalidPeselCharacter();
            }
            else
            {
                pesel[i] = (y[i]) - '0';
            }
        }

        int checksum = 9 * (pesel[0]) +
                7 * (pesel[1]) +
                3 * (pesel[2]) +
                1 * (pesel[3]) +
                9 * (pesel[4]) +
                7 * (pesel[5]) +
                3 * (pesel[6]) +
                1 * (pesel[7]) +
                9 * (pesel[8]) +
                7 * (pesel[9]);

        if(pesel[10] != (checksum%10))
        {
            throw InvalidPeselChecksum();
        }

    }
}