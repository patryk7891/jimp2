//
// Created by mikolaj on 05.03.18.
//

#include "GreatestProduct.h"

int main()
{
    int n;
    vector<int> numbers;
    cout << "Podaj ile chcesz wczytac: ";
    cin >> n;
    cout <<endl<< "Podawaj: ";

    for( int i=0; i<n; ++i )
    {
        int element;
        cin >> element;
        numbers.push_back(element);
    }

    cout << GreatestProduct(numbers, n);
}
