#include <iostream>
#include <cmath>
#include <bitset>
#include "returnException.h"

int f5(int d, double b){
    d++;
    return d;
}

int f4(int d, double b){
    if(d == 0){
        throw 4;
    }
    b = b / d;
    d++;
    d = f5(d, b);
    return d;
}

int f3(int d, double b){
    if(b == 0){
        throw 3.0; 
    }
    if(d == 0){
        throw 3;
    }
    b = b / d;
    d++;
    d = f4(d, b);
    return d;
}

int f1(int d, double b)
{
    return 0;
}
int fun2(int d, double b){
    d++;
    d = f3(d, b);
    return d;
}

int fun1(int d, double b){
    d++;
    d = fun2(d, b);
    return d;
}