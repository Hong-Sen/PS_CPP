#include <iostream>
using namespace std;

int N, M, num, S, E;
int arr[2001];
bool dp[2001][2001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>num;
        arr[i] = num;
    }
    for(int i=0; i<N; i++){
        dp[i][i] = true;
        for(int j=i-1; j>=0; j--){
            if(abs(i-j) == 1){
                dp[j][i] = arr[j] == arr[i] ? true : false;
                continue;
            }
            if(arr[i] == arr[j] && dp[j+1][i-1]) dp[j][i] = true;
            else dp[j][i] = false;
        }
    }
    cin>>M;
    for(int i=0; i<M; i++){
        cin>>S>>E;
        cout<<dp[S-1][E-1]<<"\n";
    }
}
