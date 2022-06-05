#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int reportedCnt[1001];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> user;
    map<int, int> reporting[1001];
    
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
        reporting[userId].insert({user[tmp], 0});
    }
    
    for(int i=0; i<id_list.size(); i++) {
        for(auto it = reporting[i].begin(); it != reporting[i].end(); it++){
            reportedCnt[it->first]++;
        }
    }
    
    for(int i=0; i<id_list.size(); i++) {
        int cnt = 0;
       for(auto it = reporting[i].begin(); it != reporting[i].end(); it++) {
            if(reportedCnt[it->first] >= k) cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}
