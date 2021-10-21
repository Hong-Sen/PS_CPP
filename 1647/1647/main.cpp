#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,A,B,C;
vector<pair<int,pair<int, int>>> v; // {C,{A,B}}
int parent[100001];
long long sum;
int maxCost;

int FIND(int a){
    if(parent[a] == a)   return a;
    return parent[a] = FIND(parent[a]);
}

void UNION(int a, int b){
    int A = FIND(a);
    int B = FIND(b);
    parent[A] = B;
}

bool isSameParent(int a, int b){
    if(FIND(a) == FIND(b))  return true;
    else    return false;
}

int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++)
    parent[i] = i;
    for(int i=0; i<M; i++){
        cin>>A>>B>>C;
        v.push_back({C,{A,B}});
    }
    sort(v.begin(),v.end()); // 가중치 오름차순 정렬

    for(int i=0; i<v.size(); i++){
        int v1 = v[i].second.first;
        int v2 = v[i].second.second;
        int cost = v[i].first;
        if(!isSameParent(v1, v2)){
            UNION(v1, v2);
            sum += cost;
            maxCost = max(maxCost,cost);
        }
    }
    cout<<sum-maxCost;
}
