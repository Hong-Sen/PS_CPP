//
//  main.cpp
//  1476
//
//  Created by 홍세은 on 2023/01/27.
// 26:15

#include <iostream>
#include <vector>
using namespace std;

string input;
vector<int> JGyear;
long long year;

int main(){
    getline(cin, input);
    string tmp = "";
    for(char c: input) {
        if(c == ' ') {
            JGyear.push_back(stoi(tmp));
            tmp = "";
            continue;
        }
        tmp += c;
    }
    JGyear.push_back(stoi(tmp));
    
    year = JGyear[1];
    while (1) {
        if(year % 15 == JGyear[0] && year % 19 == JGyear[2]) break;
        if(year % 15 == 0 && JGyear[0] == 15) {
            if(year % 19 == JGyear[2]) break;
            if(year % 19 == 0 && JGyear[2] == 19) break;
        }
        if(year % 19 == 0 && JGyear[2] == 19) {
            if(year % 15 == JGyear[0]) break;
            if(year % 15 == 0 && JGyear[0] == 15) break;
        }
        year += 28;
    }
    cout<<year;
}
