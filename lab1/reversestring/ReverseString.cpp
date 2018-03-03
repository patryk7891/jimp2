#include "ReverseString.h"

string reverse (string str)
{
    string reversed="";
    size_t size = str.size(); //uzyskanie z obiektu string ilości znaków
    // utworzenie nowego obiektu string na podstawie innego char*, char[], itp..

    for (int i = 0; i<size; i++)
        reversed += str[size - 1 - i];

    return reversed;
}