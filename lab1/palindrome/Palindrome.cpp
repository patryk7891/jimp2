#include "Palindrome.h"
bool is_palindrome(string str)
{
    size_t dlugosc= str.size();
    for (int i=0;i<dlugosc/2;i++)
    {
        if (str[i]!=str[dlugosc-1-i])
        {
            return false;
        }
    }
    return true;
}