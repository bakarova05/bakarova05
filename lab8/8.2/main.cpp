#include "HashTable.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "");
    HashTable ht;
    ht.add("cola", 150);
    ht.add("pepsi", 100);
    ht.add("water", 50);

    double price;
    if (ht.find("cola", price)) {
        std::cout << "Цена на cola:" << price << std::endl;
    } else {
        std::cout << "Cola не найдена в хэш-таблице" << std::endl;
    }

    if (ht.remove("pepsi")) {
        std::cout << "pepsi удалено из хэш-таблицы" << std::endl;
    } else {
        std::cout << "pepsi не найдено в хэш-таблице" << std::endl;
    }

    if (ht.isEmpty()) {
        std::cout << "Хэш-таблица пуста" << std::endl;
    } else {
        std::cout << "Хэш-таблица не пуста" << std::endl;
    }

    std::cout << "Размер хэш-таблицы:" << ht.size() << std::endl;

    return 0;
}