//
// Created by mikolaj on 22.04.18.
//

#include "Pesel.h"
#include <iostream>

int main()
{

        const char* str = "00000000000";
        try{
            academia::Pesel a(str);
        }catch(academia::InvalidPeselChecksum b){
            std::cout << "zly checksum" << std::endl;
        }catch(academia::InvalidPeselLength c) {
            std::cout << "zla dlugosc" << std::endl;
        }
        catch(academia::InvalidPeselCharacter d) {
            std::cout << "litery w peselu... troche slabo" << std::endl;
        }
        catch(...){
            std::cout << "Blad " << std::endl;
        }

    return 0;
}