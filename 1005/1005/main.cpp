#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T,N,K,D,W;
int X,Y;
int buildTime[1002];
vector<int> order[1002];
int edge[1002];
queue<int> q;
int result[1002];

void toplogical(){
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for(int i=0; i<order[top].size(); i++){
            int next = order[top][i];
            result[next] = max(result[next], result[top] + buildTime[next]);
            edge[next]--;
            if(edge[next] == 0) q.push(next);
        }
    }
    cout<<result[W]<<"\n";
}

int main(){
    cin>>T;
    while (T--) {
        cin>>N>>K;
        // order reset
        for(int i=0; i<=N; i++){
            order[i].clear();
        }
        // reset edge
        memset(edge, 0, sizeof(edge));
        // reset result
        memset(result, 0, sizeof(result));
        
        for(int i=1; i<=N; i++){
            cin>>D;
            buildTime[i] = D;
        }
        for(int i=0; i<K; i++){
            cin>>X>>Y;
            edge[Y]++;
            order[X].push_back(Y);
        }
        cin>>W;
        for(int i=1; i<=N; i++){
            if(edge[i] == 0)    q.push(i);
            result[i] = buildTime[i];
        }
        toplogical();
    }
}
