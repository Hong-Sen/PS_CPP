#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V,E;
int a,b,c;
vector<pair<int, pair<int, int>>> v;
int parent[10001];
int sum;

// 부모 찾기
int findParent(int x){
    if(parent[x] == x)  return x;
    else return parent[x] = findParent(parent[x]);
}

// 부모가 같은지 판단
bool isSameParent(int v1, int v2){
    int p1 = findParent(v1);
    int p2 = findParent(v2);
    if(p1 == p2)    return true;
    else    return false;
}

// 서로 다른 부모일 경우 두개 노드 연결
void unionFun(int v1, int v2){
    int p1 = findParent(v1);
    int p2 = findParent(v2);
    parent[p2] = p1; // 한쪽 노드의 부모 = 다른쪽 부모노드
}

int main(){
    cin>>V>>E;
    // default값: 부모 == 나
    for(int i=1; i<=V; i++)
        parent[i] = i;
    
    for(int i=0; i<E; i++){
        cin>>a>>b>>c;
        v.push_back({c, {a,b}});
    }
    sort(v.begin(),v.end());    // 가중치 오름차순 정렬
    
    for(int i=0; i<v.size(); i++){
        int v1 = v[i].second.first;
        int v2 = v[i].second.second;
        int cost = v[i].first;
        if(!isSameParent(v1, v2)){
            unionFun(v1, v2);
            sum += cost;
        }
    }
    cout<<sum;
}
