#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int calledCnt[1001];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> user;
    map<int, int> caller[1001];
    
    for(int i=0; i<id_list.size(); i++) {
        user.insert({id_list[i], i});
    }
    
    for(string s: report) {
        string tmp = "";
        int userId = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' ') {
                userId = user[tmp];
                tmp = "";
                continue;
            }
            tmp += s[i];
        }
        caller[userId].insert({user[tmp], 0});
    }
    
    for(int i=0; i<id_list.size(); i++) {
        for(auto it = caller[i].begin(); it != caller[i].end(); it++){
            calledCnt[it->first]++;
        }
    }
    
    for(int i=0; i<id_list.size(); i++) {
        int cnt = 0;
       for(auto it = caller[i].begin(); it != caller[i].end(); it++) {
            if(calledCnt[it->first] >= k) cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}
