//
//  main.cpp
//  4386
//
//  Created by 홍세은 on 2021/12/28.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
double x,y;
vector<pair<int, pair<int, int>>> v;
vector<pair<double, pair<int, int>>> value; //{별간 거리,별1 번호, 별2 번호}
int parent[101];
double sum;

int findParent(int num){
    if(parent[num] == num) return num;
    else return parent[num] = findParent(parent[num]);
}

bool isSameParent(int a, int b) {
    int p1 = findParent(a);
    int p2 = findParent(b);
    if(p1==p2) return true;
    return false;
}

void unionParent(int a, int b){
    int p1 = findParent(a);
    int p2 = findParent(b);
    parent[p2] = p1;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        v.push_back({i,{x,y}});
        parent[i] = i;
    }
    // 별끼리 모든 거리
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            double d = sqrt(pow(v[i].second.first-v[j].second.first, 2) + pow(v[i].second.second - v[j].second.second, 2));
            value.push_back({d, {i, j}});
        }
    }
    sort(value.begin(), value.end());
    
    for(int i=0; i<value.size(); i++) {
        int a = value[i].second.first; // 별1
        int b = value[i].second.second; // 별2
        double cost = value[i].first; // 별간 거리
        if(!isSameParent(a, b)) {
            unionParent(a, b);
            sum += cost;
        }
    }
    string sumToInt = to_string((int)sum);
    cout.precision(sumToInt.size()+ 2);
    cout<<sum;
}
