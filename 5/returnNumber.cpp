#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

/**
 * @brief функция выводит 2^x
 * 
 * @param x аргумент
 */
void exponentiation(unsigned x){
if(x == 0){
    std::cout << 1 << std::endl;
}
else{
    std::vector<unsigned> v = {2};
    for(int i = 1; i < x; i++){
        int e = v.size();
        for(int j = 0; j < e; j++){
            v[j] = v[j] * 2;
            }
        for(int j = 0; j < i; j++){
            if(v[j] > 9){
                if(j + 1 >= v.size()){
                    v.push_back(0);
                }
                v[j + 1] += v[j] / 10;
                v[j] %= 10;
            }
        }
    }
    for(int i = v.size() - 1; i >= 0; i--){
        std::cout << v[i];
    }
    std::cout << std::endl;
    }
}
