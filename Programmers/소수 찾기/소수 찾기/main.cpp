#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> num(10,0);
int maxNum;
bool isNotPrime[99999999];

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<>());
    maxNum = stoi(numbers);
    
    for(int i=0; i<numbers.size(); i++){
        num[int(numbers[i]) - '0']++;
    }
    
    for(int i=2; i<maxNum; i++){
        if(isNotPrime[i]) continue;
        for(int j=i+i; j<=maxNum; j+=i){
            isNotPrime[j] = true;
        }
    }
    
    for(int i=2; i<=maxNum; i++){
        if(isNotPrime[i]) continue;
        string s = to_string(i);
        vector<int> v = num;
        for(int j=0; j<s.size(); j++){
            int n = int(s[j]) - '0';
            if(v[n] == 0) break;
            v[n]--;
            if(j == s.size()-1) answer++;
        }
    }
    
    return answer;
}
