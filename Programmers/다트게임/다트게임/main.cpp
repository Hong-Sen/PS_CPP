#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> score;

void caculate(int num, char bonus, char option) {
    int result = 0;
    switch(bonus) {
        case 'S':
            result = num;
            break;
        case 'D':
            result = num * num;
            break;
        case 'T':
            result = num * num * num;
            break;
    }
    
    if(option == '*') {
        result *= 2;
        if(!score.empty()) score[score.size()-1] = score[score.size()-1] * 2;
    }
    else if(option == '#') {
        result *= -1;
    }
    score.push_back(result);
}

int solution(string dartResult) {
    int answer = 0;
    int num = 0;
    char bonus = ' ';
    char option = ' ';
    int i = 0;
    while(i < dartResult.size()) {
        char c = dartResult[i];
        if(c >= '0' && c <= '9') {
            if(i != 0) caculate(num, bonus, option);
            num = int(c) - '0';
            if(dartResult.substr(i,2) == "10") {
                num = 10;
                i++;
            }
            option = ' ';
        }
        else if(c == '*' || c == '#') option = c;
        else bonus = c;
        i++;
    }
    
    caculate(num, bonus, option);
    
    for(int i: score) {
        answer += i;
    }
    return answer;
}
