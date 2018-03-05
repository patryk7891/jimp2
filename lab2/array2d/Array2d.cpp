

#include "Array2d.h"

void przypisz_wartosc(int **tab,int n_rows, int n_columns)
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



int **Array2D(int n_rows, int n_columns)
{
    int **wektory = new int *[n_rows];
    for(int i=0; i<n_rows; i++)
    {
        wektory[i] = new int [n_columns];
    }
    przypisz_wartosc(wektory, n_rows, n_columns);

}