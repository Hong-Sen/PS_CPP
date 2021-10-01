#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int A,B;
int edge[32001];
vector<int> num[32001];
priority_queue<int, vector<int>, greater<int>> pq; //minheap
vector<int> result;

void topological(){
    while (!pq.empty()) {
        int now = pq.top();
        result.push_back(now);
        pq.pop();
        for(int i=0; i<num[now].size(); i++){
            int next = num[now][i];
            edge[next]--;
            if(edge[next] == 0){
                pq.push(next);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>A>>B;
        edge[B]++;
        num[A].push_back(B);
    }
    for(int i=1; i<=n; i++){
        if(edge[i] == 0) pq.push(i);
    }
    
    topological();
    for(int i:result) cout<<i<<" ";
}
