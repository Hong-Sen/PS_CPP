#include <string>
#include <vector>
#include <iostream>
using namespace std;

int compress(string s, int size) {
    int sSize = s.size();
    
    string result = "";
    
    string str = "";
    int i = size;
    string tmp = s.substr(0,size);
    
    while(i < sSize) {
        str = s.substr(i);
        int cnt = 0;
        if(str.find(tmp) == 0) {
            cnt++;
            while(1) {
                cnt++;
                i += size;
                if(i>= sSize) break;
                str = s.substr(i);
                if(str.find(tmp) != 0) break;
            }
            result += to_string(cnt);
        }
        result += tmp;
        
        tmp = s.substr(i, size);
        i += size;
        if(i >= sSize) result += tmp;
    }
    return result.size();
}

int solution(string s) {
    int answer = s.size();
    
    for(int i=1; i<s.size(); i++){
        answer = min(compress(s, i), answer);
    }
    return answer;
}
