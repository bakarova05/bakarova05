#include <iostream>
#include "returnNumber.h"
#include "returnPrivate.h"
#include "returnException.h"

int main() {
    int day = 15;
    int one = return_1(day);
    int two = return_2(day, day);
    int three = return_3(day);
    std::cout << one+two+three;
    //1
    std:: cout << std:: endl;

    int n = 13, m = -4, a;
    a = returnPrivate(n, m);
    std::cout << a << std::endl;
    //2
    std:: cout << std:: endl;

    int d=-6;
    double b = 0;
    try{
        a = f1(d, b);
    }
    catch(double code){
        std::cout << "Исключение типа double в функции №" << code << std::endl;
    }
    catch(int code){
        std::cout << "Исключение типа int в функции №"<< code << std::endl;
    }
    catch(...){
        std::cout << "...";
    }
    //3
    return 0;
    
}