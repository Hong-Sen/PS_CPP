#include <iostream>
using namespace std;

int main(){
    int n,m;
    int A[101][101];
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>A[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            A[i][j] += x;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
}
