#include <iostream>
#include "matrix.h"

matrix::matrix(){
    n = 2;
    m = 2;
    arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
        for(int ii = 0; ii < m; ii++){
            arr[i][ii] = 0;
        }
    }
}
matrix::matrix(int inn, int inm){
    n = inn;
    m = inm;
    arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
        for(int ii = 0; ii < m; ii++){
            arr[i][ii] = rand() % 10;
        }
    }
}

matrix::~matrix(){
    for(int i = 0; i < n; i++){
        delete[] arr[i];
    }    
    delete[] arr;
    std::cout << "-" << std::endl;
}

matrix matrix::operator + (matrix& m2){
    matrix m3 = matrix(n, m);
    if((n == m2.n) && (m == m2.m)){
        for(int i = 0; i < n; i++){
            for(int ii = 0; ii < m; ii++){
                m3.arr[i][ii] = arr[i][ii] + m2.arr[i][ii];
            }
        }
    }
    else{
        throw "Матрицы должны быть одинакового размера";
    }
    return m3;
}

matrix matrix::operator - (matrix& m2){
    matrix m3 = matrix(n, m);
    if((n == m2.n) && (m == m2.m)){
        for(int i = 0; i < n; i++){
            for(int ii = 0; ii < m; ii++){
                m3.arr[i][ii] = arr[i][ii] - m2.arr[i][ii];
            }
        }
    }
    else{
        throw "Матрицы должны быть одинакового размера";
    }
    return m3;
}

matrix matrix::operator * (int a){
    matrix m3 = matrix(n, m);
    for(int i = 0; i < n; i++){
        for(int ii = 0; ii < m; ii++){
            m3.arr[i][ii] = arr[i][ii] * a;
        }
    }
    return m3;
}

matrix matrix::operator * (matrix& m2){
    matrix m3 = matrix(n, m2.m);
    if((m == m2.n)){
        for(int i = 0; i < n; i++){
            for(int ii = 0; ii < m2.m; ii++){
                m3.arr[i][ii] = 0;
                for(int iii = 0; iii < m; iii++){
                    m3.arr[i][ii] += arr[i][iii] * m2.arr[iii][ii];
                }
            }
        }
    }
    else{
        throw "Матрицы должны быть одинакового размера";
    }
    return m3;
}

void matrix::operator = (matrix& m2){
    if(this == &m2)
    {
        *this;
    }
    if((n == m2.n) && (m == m2.m)){
        for(int i = 0; i < n; i++){
            for(int ii = 0; ii < m; ii++){
                arr[i][ii] = m2.arr[i][ii];
            }
        }
    }
    else{
        throw "Матрицы должны быть одинакового размера";
    }
}

bool matrix::operator == (matrix& m2){
    bool r = true;
    if((n == m2.n) && (m == m2.m)){
        for(int i = 0; i < n; i++){
            for(int ii = 0; ii < m; ii++){
                if(arr[i][ii] != m2.arr[i][ii]){
                    return false;
                };
            }
        }
    }
    else{
        r = false;
    }
    return r;
} 

int matrix::max(){
    int mx = -2147483648;
    for(int i = 0; i < n; i++){
        for(int ii = 0; ii < m; ii++){
            if(arr[i][ii] > mx){
                mx = arr[i][ii];
            }
        }
    }
    return mx;
}

std::ostream& operator << (std::ostream& out, matrix& m1){ 
            for(int i = 0; i < m1.n; i++){ 
                for(int ii = 0; ii < m1.m; ii++){
                    out << m1.arr[i][ii] << " ";
                }
                out << std::endl;
            }   
            return out; 
        }
std::istream& operator >> (std::istream& in, matrix& m1){
            for(int i = 0; i < m1.n; i++){ 
                for(int ii = 0; ii < m1.m; ii++){ 
                    in >> m1.arr[i][ii]; 
                }
            }   
            return in; 
        }