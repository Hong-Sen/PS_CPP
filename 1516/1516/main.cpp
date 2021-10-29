#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int buildTime[501];
vector<int> order[501];
int edge[501];
int dp[501];
queue<int> q;

void topological(){
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for(int i=0; i<order[front].size(); i++){
            int next = order[front][i];
            edge[next]--;
            if(edge[next] == 0)  q.push(next);
            dp[next] = max(dp[next], buildTime[next] + dp[front]);
            
        }
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        int num = 0;
        cin>>buildTime[i];
        while (1) {
            cin>>num;
            if(num == -1) break;
            edge[i]++;
            order[num].push_back(i);
            
        }
    }

    for(int i=1; i<=n; i++){
        if(edge[i] == 0){
            q.push(i);
            dp[i] = buildTime[i];
        }
    }
    topological();
    for(int i=1; i<=n; i++)
    cout<<dp[i]<<"\n";
}
