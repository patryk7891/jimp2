#include "ReverseString.h"

string reverse (string str)
{
    size_t size = str.size();
    if(str=="\0")
    {
        return str;
    }
    else
    {
        return reverse(str.substr(1, size-1)) + str[0];
    }
}