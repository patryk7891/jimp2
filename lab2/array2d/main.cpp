//
// Created by mikolaj on 05.03.18.
//

#include "Array2d.h"

int main()
{
    int rows, columns;
    cout << "Give me rows: ";
    cin << rows;

    cout << "Give me columns: ";
    cin << columns;

    int array = **Array2D(rows, columns);
    DeleteArray2D(array,rows, columns);

}