#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> arr[100001];
int n;
bool visited[100002];
int tmp,node;

void diameter(int start, int dis){
    visited[start] = true;
    if(dis > tmp){
        tmp = dis;
        node = start;
    }
    for(int i=0; i<arr[start].size(); i++){
        if(!visited[arr[start][i].first]){
            diameter(arr[start][i].first, dis + arr[start][i].second);
            visited[arr[start][i].first] = false;
        }
    }
}

void resetVisited(){
    for(int i=0; i<=n; i++)
        visited[i] = false;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
           int v,w = 0,d;
           cin>>v;
           while (1) {
               cin>>w;;
               if(w == -1) break;
               cin>>d;
               arr[v].push_back({w,d});
           }
       }
    diameter(1, 0); //가장 멀리떨어진 노드 구하기
    tmp = 0;
    resetVisited();
    diameter(node, 0); //거리 구하기
    cout<<tmp;
}
