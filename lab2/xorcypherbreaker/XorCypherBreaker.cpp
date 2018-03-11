//
// Created by mikolaj on 05.03.18.
//

#include "XorCypherBreaker.h"

int MostCommon(vector <int> tab)
{
    int max1=0;
    int ktora=0;
    int max_general=0;
    for(int v : tab)
    {
        max1=0;
        for(int d: tab)
        {
            if(d==v)
            {
                max1+=1;
            }
        }
        if(max1>=max_general)
        {
            max_general=max1;
            ktora=v;
        }
    }

    return ktora;
}

string FindLetter(vector <int> tab)
{
    int common = MostCommon(tab);
    int letter = common ^ 101;
    string letter1;
    letter1 = (char)common;

    return letter1;
}




string XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<string> &dictionary)
{
    vector <int> tab1;
    vector <int> tab2;
    vector <int> tab3;

    for(int i=0; i<cryptogram.size(); i++)
    {
        if(i%3==0)
        {
            tab1.emplace_back(cryptogram[i]);
        }
        else if(i%3==1)
        {
            tab2.emplace_back(cryptogram[i]);
        }
        else if(i%3==2)
        {
            tab3.emplace_back(cryptogram[i]);
        }
    }

    string passwd="";
    passwd+=FindLetter(tab1);
    passwd+=FindLetter(tab2);
    passwd+=FindLetter(tab3);

    transform(passwd.begin(),passwd.end(),passwd.begin(),::tolower);
    return passwd;
}

