#include <iostream>
#include <vector>
using namespace std;

int n,m;
int a,b;
bool visited[502];
vector<int> friends[502];
int result;

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    for(int i=0; i<friends[1].size(); i++){
        int next = friends[1][i];
        visited[next] = true;
        for(int j=0; j<friends[next].size(); j++){
            int next2 = friends[next][j];
            visited[next2] = true;
        }
    }
    for(int i=2; i<=n; i++)
        if(visited[i]) result++;
    
    cout<<result;
}

