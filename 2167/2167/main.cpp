#include <iostream>
using  namespace std;

int main(){
    int n,m,k,a,b,x,y;
    cin>>n>>m;
    int arr[301][301];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    cin>>k;
    for(int l=0; l<k; l++){
        cin>>a>>b>>x>>y;
        int sum=0;
        for(int q=a-1; q<x; q++){
            for(int w=b-1; w<y; w++)
                sum += arr[q][w];
        }
        cout<<sum<<"\n";
    }
}
