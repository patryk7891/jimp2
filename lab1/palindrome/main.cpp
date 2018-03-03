
#include "Palindrome.h"
int main() {

    string slowo;
    int cyfra;
    cout<<"---MENU---"<<endl<<"0-Wyjscie"<<endl;
    cout<<"1-Sprawdz palindrom"<<endl;
    cin>>cyfra;
    if (cyfra==1)
    {
        cout<<"Podaj slowo do sprawdzenia"<<endl;
        cin>>slowo;
        if(is_palindrome(slowo)==1)
        {
            cout<<"to jest palindrom"<<endl;
        }
        else if(is_palindrome(slowo)==0)
        {
            cout<<"to nie jest palindrom"<<endl;
        }
    }
    else if(cyfra==0)
    {
        return 0;
    }
    else
    {
        cout<<"Nie wybrano opcji z menu"<<endl;
    }
    return 0;
}