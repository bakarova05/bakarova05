#include <iostream>

int def1(int n, int t){
int r;
int p = 1;
for(r = 1; t > 0; t--){
r += p;
if(r % n == 0){
p *= -1;
}
}
return r;
}

/*int main(int, char**){
int r = def1(10, 11);
std::cout << r;
}*/