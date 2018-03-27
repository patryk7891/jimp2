#include <string>
#include <cstring>
#include <algorithm>
using ::std::swap;

class XXX {
public:
    //w zeszłym odcinku:
    //domyślny konstruktor
    XXX();
    //konstruktory parametryczne
    XXX(int param);
    XXX(const std::string name);

    //Rule of five://
    //1. konstruktor kopiujący
    XXX(const XXX &xxx);
    //2. konstruktor przenoszący
    XXX(XXX &&xxx);
    //3. operator przypisania kopiujący
    XXX &operator=(const XXX &xxx);
    //4. operator przypisania przenoszący
    XXX &operator=(XXX &&xxx);
    //5. Destruktor
    ~XXX();
};

