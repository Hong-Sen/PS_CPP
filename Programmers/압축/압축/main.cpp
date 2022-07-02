#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;
    // 1번
    for(int i=0; i<26; i++) {
        char c = 'A' + i;
        string s = "";
        dic.insert({s + c , i+1});
    }
    int idx = 27;
    int maxLen = 1;
   
    while(msg.size() > 0) {
        string s = "";
        for(int j=maxLen; j>0; j--) {
            // 2번
            s = msg.substr(0,j);
            // 3번
            if(dic.find(s) != dic.end()) {
                answer.push_back(dic[s]);
                // 4번
                dic.insert({msg.substr(0,j+1), idx++});
                maxLen = max(j+1, maxLen);
                msg.erase(0,j);
        
                break;
            }
                
        }
    }
    
    return answer;
}
