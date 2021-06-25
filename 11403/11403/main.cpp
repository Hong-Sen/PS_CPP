#include <iostream>
using namespace std;

int n;
int graph[101][101];

//i-k->j
void floyd(){
    // k = 거쳐가는 노드
    for(int k=0; k<n; k++){
        // i = 출발 노드
        for(int i=0; i<n; i++){
            // j = 도착 노드
            for(int j=0; j<n; j++){
                if(graph[i][k] && graph[k][j])
                    graph[i][j] = true;
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }
    
    floyd();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}
