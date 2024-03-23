/**#include <iostream>
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
{  int n, x;
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
**/
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

std :: string f( int N, int p) {
    std ::string code = "0123456789ABCDEF";
    std ::string sum = "";
    while (N > 0) {
        sum += code[N % p];
        N /= p;
    }
    std ::string result = "";
    for (int i = sum.length() - 1; i >= 0; i--) 
        result += sum[i];
        return result;
}
// Функция для конвертации числа N из десятичной системы в p-ичную (по значению)
    std ::string F(int N, int p) {
    std ::string result = "";
    result = f(N, p) + result; 
    return result; 
}

// Функция для конвертации числа N из десятичной системы в p-ичную (по ссылке)
void F(int N, int p, std ::string& result) {
    result = ""; // Обнуление результата
    result = f(N, p) + result; 
}
// Функция для конвертации числа N из десятичной системы в p-ичную (через указатель)
void F(int N, int p, std ::string* result) {
    *result = ""; 
    *result = f(N, p) + *result; 
}

int main() {
    setlocale(LC_ALL, "Rus");
    int p, N;

    std ::cout << "Введите основние для перевода: ";
    std ::cin >> p;
    std ::cout << "Введите число в десятичной CC для перевода: ";
    std ::cin >> N;

    // Передача параметров по значению
    std ::string resultByValue = F(N, p);
    std ::cout << "Через значения: " << resultByValue << std ::endl;

    // Передача параметров по ссылке
    std ::string resultByReference;
    F(N, p, resultByReference);
    std ::cout << "Через ссылки: " << resultByReference << std ::endl;

    // Передача параметров через указатель
    std ::string resultByPointer;
    F(N, p, &resultByPointer);
    std ::cout << "Через указатели: " << resultByPointer << std ::endl;

    return 0;
}