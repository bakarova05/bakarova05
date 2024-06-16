#include <iostream>
#include <string>
#include <algorithm>
#include "f3.h"

std::string f3(std::string equation){
    int x=0;
    int constant=0;
    int i=0;
    equation+="  ";
    while (equation[i]!='='){
        if (equation[i]=='x'){
            x++;
            i++;
            continue;
        }
        else if (equation[i]=='-'){
            if (equation[i+1]=='x'){
                x-=equation[i]-'0';
                i+=2;
                continue;
            }
            else{
                if (equation[i+2]=='x'){
                    x-=equation[i+1]-'0';
                    i+=3;
                    continue;
                }
                else {
                    constant+=equation[i+1]-'0';
                    i+=2;
                    continue;
                }
            }
        }
        else if ('0'<=equation[i] && equation[i]<='9'){
            if (equation[i+1]=='x'){
                x+=equation[i]-'0';
                i+=2;
                continue;
            }
            else{
                constant-=equation[i]-'0';
                i++;
                continue;
            }
        }
        else {
            i++;
            continue;
        }
    }

    while (i<(int)equation.size()){
        if (equation[i]=='x'){
            x--;
            i++;
            continue;
        }
        else if (equation[i]=='-'){
            if (equation[i+1]=='x'){
                x+=equation[i]-'0';
                i+=2;
                continue;
            }
            else{
                if (equation[i+2]=='x'){
                    x+=equation[i+1]-'0';
                    i+=3;
                    continue;
                }
                else {
                    constant-=equation[i+1]-'0';
                    i+=2;
                    continue;
                }
            }
        }
        else if ('0'<=equation[i] && equation[i]<='9'){
            if (equation[i+1]=='x'){
                x-=equation[i]-'0';
                i+=2;
                continue;
            }
            else{
                constant+=equation[i]-'0';
                i++;
                continue;
            }
        }
        else {
            i++;
            continue;
        }
    }

    if (x==0 && constant==0) return "Infinite";
    if (x==0 && constant!=0) return "NO";
    std::string ans = "x="; 
    ans += std::to_string(constant/x);
    return ans;
}