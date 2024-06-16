#include <iostream>
#include <math.h>
#include <vector>
 
bool f5(int fx, int fy, int t){
    bool r = false;
    std::vector<std::vector<std::vector<int>>> l{{{1, 1}}};
    for(int i = 0; i < t; i++){
        std::vector<std::vector<int>> l1;
        for(size_t ii = 0; ii < l[i].size(); ii++){
            std::vector<int> l21;
            std::vector<int> l22;
            std::vector<int> l23;
            std::vector<int> l24;
            l21.push_back(l[i][ii][0] - l[i][ii][1]);
            l21.push_back(l[i][ii][1]);
            l22.push_back(l[i][ii][0]);
            l22.push_back(l[i][ii][1] - l[i][ii][0]);
            l23.push_back(l[i][ii][0] * 2);
            l23.push_back(l[i][ii][1]);
            l24.push_back(l[i][ii][0]);
            l24.push_back(l[i][ii][1] * 2);
            l1.push_back(l21);
            l1.push_back(l22);
            l1.push_back(l23);
            l1.push_back(l24);
        }
        l.push_back(l1);
    }
    
    for(size_t i = 0; i < l.size(); i++){
        for(size_t ii = 0; ii < l[i].size(); ii++){
            if((l[i][ii][0] == fx) & (l[i][ii][1] == fy)){
                r = true;
                return r;
            }
        }
    }
    return r;
}