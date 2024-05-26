#include <iostream>
#include "returnNumber.h"
#include "returnPrivate.h"
#include "returnException.h"
#include "main.h"

int main() {
    setlocale(LC_ALL, "RU");
    unsigned x;
    std:: cout << "Введите x: ";
    std:: cin >> x;
    exponentiation(x);
    //1
    std:: cout << std:: endl;
    int n = -13, m = 3, a;
    a = returnPrivate(n, m);
    std::cout << a;
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
