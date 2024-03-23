
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