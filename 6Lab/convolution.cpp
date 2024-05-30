#include <iostream> 
#include "matrix.h"

class convolution :public matrix{  
    public:
        convolution(matrix& m1, matrix& m2);
};

convolution::convolution(matrix& m1, matrix& m2){
    if((m1.n > m2.n) && (m1.m > m2.m) && (m2.n == 3) && (m2.m == 3)){
        n = m1.n - 2;
        m = m1.m - 2;
        for(int i = 0; i < n; i++){
            arr[i] = new int[m];
            for(int ii = 0; ii < m; ii++){
                arr[i][ii] = 0;
            }
        }
        for(int i = 1; i < m1.n - 1; i++){
            for(int ii = 1; ii < m1.m - 1; ii ++){
                for(int iii = i - 1, j = 0; iii <= i + 1; iii++, j++){
                    for(int iiii = ii - 1, jj = 0; iiii <= ii + 1; iiii++, jj++){
                        arr[i - 1][ii - 1] += m1.arr[iii][iiii] * m2.arr[j][jj];
                    }
                }
            }
        }
    }
    else{
        n = 1;
        m = 1;
        for(int i = 0; i < n; i++){
            arr[i] = new int[m];
            for(int ii = 0; ii < m; ii++){
                arr[i][ii] = 0;
            }
        }
    }
} 