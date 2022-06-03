#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;
vector<pair<int, string>> v[12];

void makeSubset(int idx, string s, string origin){
    if(s.size() >= 2){
        if(m.find(s) != m.end()){
            m[s]++;
        }
        else {
             m.insert({s, 1});
        }
    }
    
    for(int i=idx; i<origin.size(); i++){
        makeSubset(i+1, s + origin[i], origin);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(string s: orders) {
        sort(s.begin(), s.end());
        makeSubset(0, "", s);
    }
    
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second == 1) continue;
        v[(it->first).size()].push_back({it->second, it->first});
    }
    
    for(int i: course){
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
