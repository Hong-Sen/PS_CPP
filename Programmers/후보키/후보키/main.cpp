#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<string>> relationList;
vector<vector<int>> attributeList[9];
vector<vector<int>> candidateKeys;
int atSize;

bool isInsideCandidate(vector<int> v) {
    for(int i=0; i<candidateKeys.size(); i++){
        int sameCnt = 0;
        for(int j=0; j<candidateKeys[i].size(); j++){
            auto it = find(v.begin(), v.end(), candidateKeys[i][j]);
            if(it == v.end())  break;
            sameCnt++;
        }
        if(sameCnt == candidateKeys[i].size()) return true;
    }
    return false;
}
    
void findUnique() {
    for(int i=1; i<9; i++){
        for(int j=0; j<attributeList[i].size(); j++){
            if(isInsideCandidate(attributeList[i][j])) continue;
            vector<string> vs;
            bool isUnique = true;
            
            for(int l=0; l<relationList.size(); l++){
                string s = "";
                for(int k=0; k<attributeList[i][j].size(); k++){
                    s += relationList[l][attributeList[i][j][k]];
                }
                auto it = find(vs.begin(), vs.end(), s);
                if(it == vs.end()){
                    vs.push_back(s);
                }
                else {
                    isUnique = false;
                   break;
                }
            }
            if(isUnique) {
                candidateKeys.push_back(attributeList[i][j]);
            }
        }
    }
}

void findSubset(int idx, vector<int> v) {
    attributeList[v.size()].push_back(v);
    
    if(idx >= atSize) return;
    
    for(int i=idx; i<atSize; i++){
        v.push_back(i);
        findSubset(i+1, v);
        v.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    relationList = relation;
    atSize = relation[0].size();
    
    vector<int> v;
    
    findSubset(0, v);
    
    findUnique();
    
    answer = candidateKeys.size();
    
    return answer;
}
