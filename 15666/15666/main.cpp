//
//  main.cpp
//  15666
//
//  Created by 홍세은 on 2021/12/10.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
vector<int> v;
bool visited[10001];
int result[8];


void makeArray(int cnt, int index){
    if(cnt == M){
        for(int i=0; i<cnt; i++)
            cout<<result[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=index; i<v.size(); i++){
        result[cnt] = v[i];
        makeArray(cnt+1, i);
    }
}

int main(){
    cin>>N>>M;
    int x;
    for(int i=0; i<N; i++){
        cin>>x;
        if(!visited[x]){
            visited[x] = true;
            v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    makeArray(0, 0);
}
