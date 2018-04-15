
#include "Point.h"
#include <iomanip>

using ::std::istream;
using ::std::ostream;
using ::std::ws;

//Helper functions:
void CheckNextChar(char c, istream* is) {
    int next_char = is->peek();
    if (next_char != c) {

    }
    is->ignore();
}

void IgnoreWhitespace(istream* is) {
    (*is) >> ws;
}

double ReadNumber(istream* is) {
    double d;
    (*is) >> d;
    return d;
}

void WriteNumber(ostream* os, double a) {
    (*os) <<"Numer to: "<< a<<std::endl;
}

//metody klasy Point

void Point::SetX(double x)
{
    x_ = x;
}

void Point::SetY(double y)
{
    y_ = y;
}

double Point::GetX()
{
    return x_;
}

double Point::GetY()
{
    return y_;
}


//operatory

istream& operator>>(istream & input, Point& p){

    CheckNextChar('(', &input);
    p.SetX(ReadNumber(&input));
    CheckNextChar(',', &input);
    IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    CheckNextChar(')', &input);

    return input;      // Umożliwia cin >> a >> b >> c;
}

ostream& operator<<(ostream & output, Point& p){
    WriteNumber(&output, p.GetX());
    WriteNumber(&output, p.GetY());


    return output;
}
