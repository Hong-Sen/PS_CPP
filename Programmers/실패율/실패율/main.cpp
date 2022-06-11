#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

double userInStage[501][2]; // {도달한 플레이어수, 현재 스테이지에 도달한 플레이어수}
vector<pair<double,int>> failure;

bool cmp(pair<double,int> a, pair<double,int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    for(int i:stages) {
        if(i == N+1) {
            for(int j=1; j<=N; j++){
                userInStage[j][0]++;
            }
            continue;
        }
        for(int j=1; j<=i; j++){
            userInStage[j][0]++;
        }
        userInStage[i][1]++;
    }
    
    for(int i=1; i<=N; i++){
        if(userInStage[i][0] == 0){
            failure.push_back({0,i});
            continue;
        }
        failure.push_back({double(userInStage[i][1] / userInStage[i][0]), i});
    }
    
    sort(failure.begin(), failure.end(), cmp);
    
    for(int i=0; i<failure.size(); i++){
        answer.push_back(failure[i].second);
    }
    
    return answer;
}
