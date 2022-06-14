#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    string s = "";
    while(1) {
        if(n < 3){
            s = to_string(n) + s;
            break;
        }
        s = to_string(n%3) + s;
        n /= 3;
    }
    
    for(int i=0; i<s.size(); i++){
        answer += pow(3,i) * int(s[i] - '0');
    }
    return answer;
}
