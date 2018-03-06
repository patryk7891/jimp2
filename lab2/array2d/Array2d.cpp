

#include "Array2d.h"



void FillArray2D(int n_rows, int n_columns, int **tab)
{
    int liczba=1;

    for(int i=0;i<n_rows;i++)
    {
        for(int j=0;j<n_columns;j++)
        {
            * (*(tab+i)+j) = liczba;
            liczba++;
        }
    }
}


void drukuj(int **tab, int n_rows, int n_columns)
{

    for(int i=0;i<n_rows;i++)
    {
        for(int j=0;j<n_columns;j++)
        {
            cout << * (*(tab+i)+j) << " ";
        }
        cout << endl;
    }
}


void DeleteArray2D(int **array, int n_rows, int n_columns)
{
    for(int i(0); i < n_rows; ++i )
    {
        delete [] array[i]; //uwolnienie pamieci
    }
    delete [] array; //uwolnienie pamieci

}

int **Array2D(int n_rows, int n_columns)
{
    if(n_rows <= 0 || n_columns <=0)
    {
        return 0;
    }

    int **wektory = NewArray2D(n_rows, n_columns);

    FillArray2D(n_rows, n_columns, wektory);
    drukuj(wektory, n_rows, n_columns);

    return wektory;

}

int **NewArray2D(int n_rows, int n_columns) {
    int **wektory = new int *[n_rows];
    for(int i=0; i<n_rows; i++)
    {
        wektory[i] = new int [n_columns];
    }
    return wektory;
}

