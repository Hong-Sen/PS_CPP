//
//  main.cpp
//  15686
//
//  Created by 홍세은 on 2021/12/18.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N,M;
int map[52][52];
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
int selectArr[14];
int result[2502];
int answer = 987654321;

int caculateDis(){
    for(int i=0; i<home.size(); i++){
        result[i] = 1000;
    }
    for(int i=0; i<M; i++){
        int row = chicken[selectArr[i]].first;
        int col = chicken[selectArr[i]].second;
        for(int j=0; j<home.size(); j++){
            int dis = abs(row-home[j].first) + abs(col-home[j].second);
            result[j] = min(result[j], dis);
        }
    }
    int sum = 0;
    for(int i=0; i<home.size(); i++){
        sum += result[i];
    }
    return sum;
}

void selectChicken(int cnt, int start) {
    if(cnt == M){
        answer = min(answer, caculateDis());
    }
    for(int i=start; i<chicken.size(); i++){
        selectArr[cnt] = i;
        selectChicken(cnt+1, i+1);
    }
}


int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>map[i][j];
            if(map[i][j] == 1) home.push_back({i,j});
            if(map[i][j] == 2) chicken.push_back({i,j});
        }
    }
    selectChicken(0, 0);
    cout<<answer;
}
