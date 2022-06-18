#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

long long answer;
string oper;
vector<long long> nums;
string operKind;
vector<string> priority;
string operTmp;
vector<long long> numsTmp;

void print() {
    cout<<"operTmp: "<<operTmp<<"\n";
    cout<<"numsTmp: ";
    for(int i:numsTmp) {
        cout<<i<<" ";
    }
    cout<<"\n";
}

void caculate(int idx) {
    long long result = 0;
    switch (operTmp[idx]) {
        case '*':
            result = numsTmp[idx] * numsTmp[idx+1];
            break;
        case '-':
            result = numsTmp[idx] - numsTmp[idx+1];
            break;
        case '+':
            result = numsTmp[idx] + numsTmp[idx+1];
            break;
        default:
            break;
    }
    
    operTmp.erase(idx, 1);
    
    numsTmp[idx] = result;
    for(int i=idx+1; i<numsTmp.size()-1; i++){
        numsTmp[i] = numsTmp[i+1];
    }
    numsTmp.pop_back();
    
    if(numsTmp.size() == 1){
        answer = max(answer, abs(numsTmp[0]));
        return;
    }
}

void setPriority(string s) {
    if(s.size() == operKind.size()) {
        priority.push_back(s);
        return;
    }
    
    for(char c: operKind){
        if(s.find(c) < operKind.size()) continue;
        setPriority(s + c);
    }
}

long long solution(string expression) {
    answer = 0;
    oper = "";
    string str = "";
    for(int i=0; i<expression.size(); i++){
        char c = expression[i];
        if(c == '*' || c == '-' || c == '+') {
            oper += c;
            nums.push_back(stoi(str));
            if(operKind.find(c) >= operKind.size()) operKind += c;
            str = "";
            continue;
        }
        str += c;
    }
    nums.push_back(stoi(str));
    
    setPriority("");
    
    for(string s: priority) {
        operTmp = oper;
        numsTmp = nums;
        for(char c: s) {
            while(operTmp.find(c) < operTmp.size()) {
                caculate(operTmp.find(c));
            }
        }
    }
    
    
    
    
    return answer;
}
