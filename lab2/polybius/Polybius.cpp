//
// Created by mikolaj on 05.03.18.
//

#include "Polybius.h"

string PolybiusCrypt(string message)
{
    transform(message.begin(), message.end(), message.begin(), ::toupper);
    string ret = "";
    string tab[6][6] = {{"0","1","2","3","4","5"},{"1","A","B", "C", "D", "E"}, {"2","F","G","H","I","K"}, {"3","L","M","N","O","P"}, {"4","Q","R","S","T","U"}, {"5","V","W","X","Y","Z"}};

    long int siz = message.size();

    for(int j=0; j<siz; j++)
    {
        for(int i=0; i<6; i++)
        {
            for(int k=0; k<6; k++)
            {
                if(message.substr(j,1)==tab[i][k])
                {
                    ret += to_string(i);
                    ret += to_string(k);
                }
            }
        }
        if(message.substr(j,1)=="J")
        {
            ret += "2";
            ret += "4";
        }
    }

    return ret;
}

string PolybiusDecrypt(string crypted)
{
    string tab[6][6] = {{"0", "1","2","3","4","5"},{"1","A","B", "C", "D", "E"}, {"2","F","G","H","I","K"}, {"3","L","M","N","O","P"}, {"4","Q","R","S","T","U"}, {"5","V","W","X","Y","Z"}};


    string ret = "";
    int siz = crypted.size();

    string str1;
    string str2;

    for(int i=0; i<siz; i+=2)
    {
        str1 = crypted[i];
        str2 = crypted[i+1];
        ret += tab[atoi(str1.c_str())][atoi(str2.c_str())];
    }

    transform(ret.begin(), ret.end(), ret.begin(), ::tolower);

    return ret;

}