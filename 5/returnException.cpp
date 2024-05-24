#include <iostream>
#include <cmath>
#include <bitset>

int fun5(int a, double b){
    a++;
    return a;
}

int fun4(int a, double b){
    if(a == 0){
        throw 4;
    }
    b = b / a;
    a++;
    a = fun5(a, b);
    return a;
}

int fun3(int a, double b){
    if(b == 0){
        throw 3.0; 
    }
    if(a == 0){
        throw 3;
    }
    b = b / a;
    a++;
    a = fun4(a, b);
    return a;
}

int fun2(int a, double b){
    a++;
    a = fun3(a, b);
    return a;
}

int fun1(int a, double b){
    a++;
    a = fun2(a, b);
    return a;
}