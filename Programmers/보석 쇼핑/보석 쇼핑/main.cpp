// 55:00
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> m;
int total;
int totalSize = 100001;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int s = 0, e = 0;
    for(string s: gems) {
        m.insert({s,1});
    }
    total = m.size();
    m.clear();
    for(string s: gems) {
        m[s]++;
        if(m.size() == total) break;
        e++;
    }
    
    while(1) {
        if(e - s + 1 < totalSize) {
            totalSize = e - s + 1;
            answer.clear();
            answer.push_back(s+1);
            answer.push_back(e+1);
        }
        string key = gems[s];
        m[key]--;
        s++;
        if(m[key] == 0) {
            e++;
            for(; e<gems.size(); e++) {
                m[gems[e]]++;
                if(gems[e] == key) break;
            }
        }
        if(e >= gems.size()) break;
    }
    
    return answer;
}
