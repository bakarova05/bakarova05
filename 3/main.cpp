/*/1
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
/**
 * @brief функция сравнивает первые буквы слов в векторе с буквами строки s.
 * Если наше words[i][0]!=s[i] условие верно, то прекращаем функцию
 * 
 * @param s строка 
 * @param words вектор из строк
 * @return bool - результат проверки

bool f(const std::string &s, const std::vector<std::string> &words){ 
    int sz1=s.length();
    int sz2=words.size();
    if(sz1!=sz2){
        return false;
    }
    for (int i=0; i<sz; ++i){ 
        if (words[i][0]!=s[i]){
            return false;
        }
    }
    return true;
} 

int main()
{
   setlocale(LC_ALL, "RUS");
   std::string s="tou";
   std::vector<std::string> words={"tomsk", "polytechnic", "university"};
   std::cout << f(s, words);
   }
*/



/*/2
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
/**
 * @brief мы перебираем буквы строки (зеркальный ли)
 * если находим первое несовпадающее условие, то сразу прекращаем поиски
 * если не находим, то строка зеркальная
 * @param s строка, которую мы должны ввести ручками
 * @return bool - результат проверки
 
bool f(const std::string &s){ 
    int sz=s.length();
    for (int i=0; i<sz; ++i){ 
        if (s[i]!=s[sz-i-1]){
            return false;
        }
    }
    return true; 
} 

int main()
{
   setlocale(LC_ALL, "RUS");
   std::string s;
   std::cout << "Введите строку: ";
   std::getline(std::cin, s);
   std::cout << std::endl;
   for(int i=0; i<sz; i++){
    if(s[i]==' '){
        s.erase(i, 1); //удаляем пробелы
        i--; //передвигаем индекс, так как могут быть двойные пробелы
        
    }
   }
   std::cout << f(s);
}
*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
 /**
     * @brief Функция, возвращающая максимальный счёт int1 среди множества слов str1, сформированных из вектора char1
     * создаём пустой вектор букв char2, добавляем в место букв их количество. Таким же образом создаем вектор str2.
     * сравниваем char2 и str2, и если char2 меньше чем str2, то тогда не хватает букв для составления слов, или их вообще нет.
     * прекращаем работу.
     * @param str1 Вектор строк
     * @param char1 Вектор символов
     * @param int1 Вектор подсчёта с целочисленными значениями, определяющий счёт за каждый символ в слове
     * 
     * @return Возвращает максимальный счёт среди множества слов
  */  
int f(std::vector <std::string> str1, std::vector <char> char1, std::vector <int> int1){
        int char2[26]={0};
        int maxi=0;
        for (int i=0; i<(int)char1.size(); i++){
            char2[char1[i]-'a']++;
        }
        for (size_t i=0; i<str1.size(); i++){
            bool fl=true;
            std::string word = str1[i];
            int str2[26]={0};
            for (int j=0; j<(int)word.size(); j++){
                str2[word[j]-'a']++;
            }
            for (int k=0; k<26; ++k){
                if (char2[k]<str2[k]){
                    fl=false;
                    break;
                }
            }
            if (!fl){
                continue;
            }
            int a=0;
            for (int j=0; j<(int)word.size(); j++){
                a = a + int1[word[j]-'a'];
            }
            if (maxi<a) 
            maxi=a;
        }
        return maxi;
    }
int main()
{
   setlocale(LC_ALL, "RUS");
   std::vector <std::string> words={"cat", "dog", "pen", "fog"};
   std::vector <char> letter={'a', 'c', 't', 'o', 'g', 'p', 'e', 'n', 'f'};
   std::vector <int> score={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
   std::cout << f(words, letter, score);
}

