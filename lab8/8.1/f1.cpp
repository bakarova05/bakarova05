#include "Hashf1.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


std::vector<std::string> votedNames;
std::vector<unsigned int> votedHashes;
int duplicateCount = 0;

void enrolled(const std::string& filename) {
    std::ifstream file(filename);
    std::string name;
    while (std::getline(file, name)) {
        unsigned int hashValue = customHash(name);
        bool isDuplicate = false;
        for (unsigned int hash : votedHashes) {
            if (hash == hashValue) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            votedNames.push_back(name);
            votedHashes.push_back(hashValue);
        } else {
            duplicateCount++;
        }
    }
}

void unenrolled(const std::string& name) {
    unsigned int hashValue = customHash(name);
    bool isDuplicate = false;
    for (unsigned int hash : votedHashes) {
        if (hash == hashValue) {
            isDuplicate = true;
            break;
        }
    }
    if (!isDuplicate) {
        votedNames.push_back(name);
        votedHashes.push_back(hashValue);
    } else {
        duplicateCount++;
    }
}

void printResults() {
    std::cout << "Число избирателей: " << votedNames.size() << std::endl;
    std::cout << "Количество дубликатов: " << duplicateCount << std::endl;
    std::cout << "Избиратели: " << std::endl;
    for (const auto& name : votedNames) {
        std::cout << name << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "");
    std::string filename = "students.txt";
    enrolled(filename);

    std::string name;
    while (true) {
        std::cout << "Введите фамилию или end: ";
        std::getline(std::cin, name);
        if (name == "end") {
            break;
        }
        unenrolled(name);
    }

    printResults();
    return 0;
}