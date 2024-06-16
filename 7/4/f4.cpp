#include "f4.h"
#include <algorithm>
#include <iostream>

int f4(const std::vector<std::string>& times) {
    std::vector<int> minutes;

    for (const auto& timeStr : times) {
        int hour = std::stoi(timeStr.substr(0, 2));
        int minute = std::stoi(timeStr.substr(3, 2));
        minutes.push_back(hour * 60 + minute);
    }

    std::sort(minutes.begin(), minutes.end());

    int minf = INT_MAX;
    for (size_t i = 1; i < minutes.size(); ++i) {
        minf = std::min(minf, minutes[i] - minutes[i - 1]);
    }

    return minf;
}