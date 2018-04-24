//
// Created by mikolaj on 22.04.18.
//

#include <iostream>
#include "BallException.h"

int main()
{
    try
    {
        drawBall();
    }
    catch(BallException b)
    {
        cout << "Blad podczas rysowania kuli" << endl;
    }
    catch(CircleException a)
    {
        cout << "Blad podczas rysowania kola" << endl;
    }
    catch(...)
    {
        cout<<"Blad inny"<<endl;
    }
}