#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> summa(vector <int> vec1, vector <int> vec2, int sz){

vector <int> result; // число-вектор с результатом
result.push_back(0); //добавляем 0 в вектор резульата
result[0]=(vec1[0]+vec2[0])%10; // нулевой элемент равен остатку от десяти (столбиком суммируем)
int md=(vec1[0]+vec2[0])/10; // остаток md
for (int i=1; md>0 || i<sz; ++i){ //когда остаток md больше нуля 
vec1.push_back(0); //добавляем 0
vec2.push_back(0); // Добавляем 0
result.push_back(0); 
result[i]=(vec1[i]+vec2[i]+md)%10;
md=(vec1[i]+vec2[i]+md)/10;
}
return result;
}

int main()
{
   setlocale(0, "");
   int n, x;
   cout << "Введите n: ";
   cin >> n;
    vector<int> res={1};
    for(int i=2; i<=n; i++){
        vector<int> vec=res;
        for (int j=0; j<i-1; j++){
            res = summa(res, vec, res.size());
        } 
    }
    for (int i=0; i<res.size(); i++){
        cout << res[res.size()-i-1];
    }
    cout << '\n';
}
