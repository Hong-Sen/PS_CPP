#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    int time = 0;
    string answer = "(None)";
    
    for(string musicinfo: musicinfos) {
        string startTime = musicinfo.substr(0,5);
        string endTime = musicinfo.substr(6,5);
        musicinfo.erase(0,12);
        int commaIdx = musicinfo.find(',');
        string title = musicinfo.substr(0,commaIdx);
        string code = musicinfo.substr(commaIdx+1);
        
        // 악보를 음별로 나누어 저장
        vector<string> codes;
        int idx = 0;
        while(idx < code.size()) {
            if(code[idx+1] == '#') {
                codes.push_back(code.substr(idx,2));
                idx += 2;
            }
            else {
                codes.push_back(code.substr(idx,1));
                idx += 1;
            }
        }
        
        int playTime = stoi(endTime.substr(0,2)) * 60 + stoi(endTime.substr(3,2)) - stoi(startTime.substr(0,2)) * 60 - stoi(startTime.substr(3,2));
        int codesSize = codes.size();
        
        // 악보 전체 만들기
        if(codes.size() < playTime) {
             for(int i=0; i<playTime-codesSize; i++) {
                 code += codes[i % codes.size()];;
             }
        }
        else {
            for(int i=0; i<codesSize-playTime; i++) {
                code.erase(code.size() - codes[codes.size()-1].size());
                codes.pop_back();
            }
        }
        
        // m 찾기
        while(code.size() > 0) {
           if(code.substr(0,m.size()) == m && code[code.find(m)+m.size()] != '#') {
                if(time < playTime) answer = title;
                break;
            }
            else {
                code.erase(0,1);
            }
        }
    }
    
    return answer;
}
