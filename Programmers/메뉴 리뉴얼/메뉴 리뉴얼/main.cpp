#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

 map<string, int> m;
 vector<pair<int, string>> v[11];
 vector<int> courseList;

bool isIncludeCourse(string s){
    int n = s.size();
    
    for(int i: courseList) {
        if(n == i) return true;
    }
    
    return false;
}

void makeSubset(int idx, string s, string origin){
    if(s.size() >= 2){
        if(isIncludeCourse(s)) {
           if(m.find(s) != m.end()){
            m[s]++;
        }
        else {
             m.insert({s, 2});
        }
      }
    }
    
    for(int i=idx; i<origin.size(); i++){
        makeSubset(i+1, s + origin[i], origin);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    courseList = course;
    vector<string> answer;
    
    for(string s: orders){
        sort(s.begin(), s.end());
    }
    
    for(int i=0; i<orders.size()-1; i++){
        for(int j=i+1; j<orders.size(); j++) {
            string s = "";
            
            for(int k=0; k<orders[j].size(); k++){
                char c = orders[j][k];
                if(orders[i].find(c) <= orders[i].size()) s += c;
            }
            
            makeSubset(0, "", s);
            
        }
    }
    
    for(auto it = m.begin(); it != m.end(); it++) {
        v[(it->first).size()].push_back({it->second, it->first});
    }
    
    for(int i=2; i<11; i++){
        sort(v[i].begin(), v[i].end(), greater<>());
        int maxMenu = v[i][0].first;
        for(int j=0; j<v[i].size(); j++){
            if(v[i][j].first != maxMenu) break;
            answer.push_back(v[i][j].second);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
