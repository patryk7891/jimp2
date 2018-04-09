//
// Created by mikolaj on 08.04.18.
//

#include "Matrix.h"


namespace algebra
{
    Matrix::Matrix()
    {
        n_cols = 0;
        n_rows = 0;
    }

    Matrix::Matrix(int rows, int cols)
    {
        if ((rows>=0)&&(cols>=0))
        {
            n_rows = rows;
            n_cols = cols;

            std::complex<double> **tablica = new std::complex<double>  *[rows];
            for (int i=0; i< rows; i++)
            {
                tablica[i] = new std::complex<double>[cols];
            }
            array = tablica;
        }
    }

    Matrix::Matrix(const Matrix &matrix)
    {
        n_rows = matrix.n_rows;
        n_cols = matrix.n_cols;

        std::complex<double> **tablica = new std::complex<double> *[n_rows];

        for (int i=0; i<n_rows; i++)
        {
            tablica[i] = new std:: complex<double> [n_cols];
        }

        for(int k=0; k<n_rows; k++)
        {
            for(int j=0; j<n_cols; j++)
            {
                tablica[k][j] = matrix.array[k][j];
            }
        }

        array = tablica;

    }

    std::complex<double> funkcja(std::string value_s)
    {
        std::string re = value_s.substr(0,value_s.find('i'));
        std::string im = value_s.substr(value_s.find('i')+1,value_s.length());

        double r = std::stod(re);
        double i = std::stod(im);

        std::complex<double> ret;

        ret.real(r);
        ret.imag(i);

        return ret;
    }

    Matrix::Matrix(std::string matrix_str)
    {

        long colonsy = std::count(matrix_str.begin(), matrix_str.end(), ';');
        n_rows = int(colonsy + 1);

        std::string tmp = matrix_str.substr(0, matrix_str.find(';'));

        long spac = std::count(tmp.begin(), tmp.end(), ' ');
        n_cols = int(spac + 1);

        std::complex<double> **tablica = new std::complex<double>  *[n_rows];
        for (int i=0; i< n_rows; i++)
        {
            tablica[i] = new std::complex<double>[n_cols];
        }
        array = tablica;

        std::string line;
        line = matrix_str.substr(1, matrix_str.length() - 2);
        std::regex pattern {R"(\w+\.*\w+\.*\w+)"};

        std::smatch matches;

        int row = 0;
        int col =0;

        while (std::regex_search (line, matches, pattern)) {
            for (auto match: matches)
            {

                std::string x = match.str();
                array[row][col] = funkcja(x);
                col++;
                if (col > n_cols - 1)
                {
                    col = 0;
                    row++;
                }
            }

            line = matches.suffix().str();
        }
    }


    Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> matrix_list)
    {
        int rows = int(matrix_list.size());
        int cols;
        for (auto row : matrix_list)
        {
            cols = int(row.size());
            break;

        }

        n_rows = rows;
        n_cols = cols;

        std::complex<double> **tablica = new std::complex<double> *[n_rows];

        for (int i=0; i<n_rows; i++)
        {
            tablica[i] = new std:: complex<double> [n_cols];
        }

        array = tablica;

        int i = 0;
        int j = 0;

        for(std::vector<std::complex<double>> row: matrix_list )
        {
            j=0;
            for(std::complex<double> el : row)
            {
                array[i][j] = el;
                j++;
            }
            i++;
        }

    }

    Matrix::~Matrix()
    {
        for (int i=0; i<n_rows; i++)
        {
            delete [] array [i];
        }
        delete [] array;
    }

    Matrix & Matrix :: operator=(const Matrix& matrix)
    {
        if(this== &matrix)
        {
            return *this;
        }

        for(int i=0; i < n_rows; i++)
        {
            delete [] array[i];
        }

        delete [] array;


        n_rows = matrix.n_rows;
        n_cols = matrix.n_cols;

        std::complex<double> **tablica = new std::complex<double> *[n_rows];

        for (int i=0; i<n_rows; i++)
        {
            tablica[i] = new std:: complex<double> [n_cols];
        }

        for(int k=0; k<n_rows; k++)
        {
            for(int j=0; j<n_cols; j++)
            {
                tablica[k][j] = matrix.array[k][j];
            }
        }

        array = tablica;
    }

    Matrix Matrix::Add(const Matrix &matrix) const
    {
        if(n_rows==matrix.n_rows && n_cols == matrix.n_cols)
        {
            Matrix newly(n_rows, n_cols);

            for(int i=0; i<n_rows; i++)
            {
                for(int j=0; j<n_cols; j++)
                {
                    newly.array[i][j] = array[i][j] +  matrix.array[i][j];
                }
            }

            return newly;
        }

        else
        {
            return Matrix();
        }
    }

    Matrix Matrix::Sub(const Matrix &matrix)
    {
        if(n_rows==matrix.n_rows && n_cols == matrix.n_cols)
        {
            Matrix newly(n_rows, n_cols);

            for(int i=0; i<n_rows; i++)
            {
                for(int j=0; j<n_cols; j++)
                {
                    newly.array[i][j] = array[i][j] -  matrix.array[i][j];
                }
            }

            return newly;
        }

        else
        {
            return Matrix();
        }
    }

    Matrix Matrix::Mul(const Matrix &matrix) {
        if (n_cols == matrix.n_rows)
        {
            std::complex<double> num = 0i;

            Matrix new_matrix(n_rows, matrix.n_cols);

            for(int i= 0; i<n_rows; i++)
            {
                for(int j=0; j<matrix.n_cols;j++)
                {
                    num = 0i;
                    for(int k=0; k<n_cols; k++)
                    {
                        num+=array[i][k]*matrix.array[k][j];
                    }

                    new_matrix.array[i][j] = num;
                }
            }
            return new_matrix;
        }
        else
        {
            Matrix non(0,0);
            return non;
        }

    }

    Matrix Matrix::Pow(int power) {

        if(power==0)
        {
            Matrix new_matrix(n_rows, n_cols);
            for(int i=0; i<n_rows; i++)
            {
                for(int j=0; j<n_cols; j++)
                {
                    if(i==j)
                        new_matrix.array[i][j] = 1;
                    else
                        new_matrix.array[i][j] = 0;
                }
            }
            return new_matrix;
        }
        else
        {
            Matrix new_matrix(*this);
            Matrix first_matrix(*this);

            while(power > 1)
            {
                new_matrix = new_matrix.Mul(first_matrix);
                power--;
            }
            return new_matrix;
        }
    }

    Matrix Matrix::Div(const Matrix &matrix)
    {
        return Matrix();
    }

    std::pair<size_t, size_t> Matrix::Size() {
        return std::pair<size_t, size_t>{n_rows,n_cols};
    }

    std::string ret_string(double stri) {
        std::string ret = std::to_string(stri);

        for(int i=int(ret.length())-1; i>=0; i--)
        {
            if (ret[i] != '0')
            {
                break;
            }
            else
            {
                ret = ret.substr(0, ret.length()-1);
            }
        }
        if (ret[ret.length()-1]=='.')
            ret = ret.substr(0, ret.length()-1);
        return ret;
    }

    std::string Matrix::Print() const
    {
        if (n_cols == 0)
        {
            return "[]";
        }

        std::string ret ="[";

        for(int i=0; i<n_rows; i++)
        {
            for( int j=0; j<n_cols; j++)
            {
                ret += ret_string(array[i][j].real());
                ret += "i";
                ret+= ret_string(array[i][j].imag());

                if(j!=n_cols-1)
                {
                    ret += ", ";
                }
            }

            if(i!=n_rows-1)
            {
                ret += "; ";
            }
        }

        ret += "]";
        return ret;
    }

}