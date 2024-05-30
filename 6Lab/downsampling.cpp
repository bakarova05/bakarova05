#include "matrix.h"
#include <iostream>


class downsampling: public matrix{
    public:
        downsampling(matrix& m1);
};

downsampling::downsampling(matrix& m1) : matrix(){
    if((m1.n > 2) && (m1.m > 2)){
        n = m1.n - 1;
        m = m1.m - 1;
        for(int i = 0; i < n; i++){
            arr[i] = new int[m];
            for(int ii = 0; ii < m; ii++){
                arr[i][ii] = 0;
            }
        }
        int mx;
        for(int i = 0; i < n; i++){
            for(int ii = 0; ii < n; ii++){
                mx = -2147483648;
                for(int iii = 0; iii < 2; iii++){
                    for(int iiii = 0; iiii < 2; iiii++){
                        if(m1.arr[i + iii][ii + iiii] > mx){
                            mx = m1.arr[i + iii][ii + iiii];
                        }
                    }
                }
                arr[i][ii] = mx;
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