
#include "ReverseString.h"

int main() {

    string word = "";

    char character;
    cout << "Podaj slowo: "<< endl;
    while((character = getchar())!= 10)
    {
        word += character;
    }
    cout<<reverse(word)<<" "<<endl;

    return 0;
}