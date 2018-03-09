//
// Created by mikolaj on 05.03.18.
//

#include "Polybius.h"

int main(int argc, char* argv[])
{

    switch(atoi(argv[3]))
    {
        case 0:

            ifstream myfile(argv[1]);
            string crypted = "";
            string help;

            if(!myfile)
            {
                return 0;
            }

            while(!myfile.eof())
            {
                getline(myfile, help);
                crypted+=help;
            }

            myfile.close();

            ofstream mfile (argv[2], ios_base::in | ios_base::app);

            if(!mfile)
            {
                cout << "Nie można otworzyć pliku!" << endl;
            }

            mfile << PolybiusDecrypt(crypted);

            mfile.close();

            return 0;

        case 1:

            ifstream file(argv[1]);
            string message = "";
            string bufor;

            if(!file)
            {
                return 0;
            }

            while(!file.eof())
            {
                getline(file, bufor);
                message += bufor;
            }
            file.close();

            ofstream myyfile (argv[2], ios_base::in | ios_base::app);

            if(!mfile)
            {
                cout << "Nie można otworzyć pliku!" << endl;
            }

            myyfile << PolybiusCrypt(message);
            myyfile.close();

            return 0;
    }
}