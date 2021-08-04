#include <iostream>
using namespace std;

int arr[100001];
int sum[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    int tmp = 0;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        tmp += arr[i];
        sum[i] = tmp;
    }
    
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        if(a == 0){
            cout<<sum[b]<<"\n";
        }
        else{
            cout<<sum[b] - sum[a-1]<<"\n";
        }
    }
}
