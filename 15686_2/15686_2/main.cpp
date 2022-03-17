//
//  main.cpp
//  15686_2
//
//  Created by 홍세은 on 2022/03/16.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n,m;
int map[51][51];
int cityChickenStreet = 10000;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;

void calcDis(vector<pair<int, int>> v){
    int sum = 0;
    for(int i=0; i<home.size(); i++) {
        int chickenStreet = 10000;
        for(int j=0; j<m; j++) {
            chickenStreet = min(abs(home[i].first - v[j].first) + abs(home[i].second - v[j].second), chickenStreet);
        }
        sum += chickenStreet;
    }
    cityChickenStreet = min(sum, cityChickenStreet);
}

void selectChicken(int idx, int vIdx, vector<pair<int, int>> selectedChicken){
    if(idx == m) {
        calcDis(selectedChicken);
        return;
    }
    for(int i=vIdx; i<chicken.size(); i++){
        selectedChicken[idx].first = chicken[i].first;
        selectedChicken[idx].second = chicken[i].second;
        selectChicken(idx+1, i+1, selectedChicken);
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
            if(map[i][j] == 1) home.push_back({i,j});
            if(map[i][j] == 2) chicken.push_back({i,j});
        }
    }
    vector<pair<int, int>> selectedChicken(14,{0,0});
    selectChicken(0, 0, selectedChicken);
    cout<<cityChickenStreet;
}
