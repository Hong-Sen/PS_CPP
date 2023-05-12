#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string,int> mp;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int cnt = 100001;
    
    for(string s: gems) {
        mp[s]++;
    }
    
    int kind = mp.size();
    int s = 0, e = 0;
    map<string,int> buy;
    
    while(s <= e) {
        if(e >= gems.size() && buy.size() < kind) break;
        
        if(buy.size() >= kind) {
            if(buy[gems[s]] == 1) buy.erase(gems[s]);
            else buy[gems[s]]--;
            s++;
        }
        else {
            buy[gems[e++]]++;
        }
        
        if(buy.size() == kind && cnt > (e-s)) {
            cnt = e - s;
            answer.clear();
            answer.push_back(s+1);
            answer.push_back(e);
        }
    }
    
    return answer;
}
