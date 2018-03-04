//
// Created by patryk on 04.03.18.
//

#include "DoubleBasePalindromes.h"

bool is_palindrome(string str)
{
    size_t dlugosc = str.size();

    for (int i = 0; i < dlugosc / 2; i++)
    {
        if (str[i] != str[dlugosc - 1 - i])
        {
            return false;
        }
    }
    return true;
}

bool is_double(int number)
{
    string liczba_binary = bitset<32>(number).to_string();
    string liczba_decimal = to_string(number);

    while(true)
    {
        if(liczba_binary[0]=='0')
        {
            liczba_binary.erase(0, 1);
        }
        else
        {
            break;
        }
    }

    if (is_palindrome(liczba_binary) && is_palindrome(liczba_decimal))
    {
        return true;
    }
    else
    {
        return false;
    }
}


uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    uint64_t sum=0;

    for(int i=1;i<max_vaule_exculsive;i++)
    {
        if (is_double(i))
        {
            sum+=i;
        }
    }

    return sum;
}