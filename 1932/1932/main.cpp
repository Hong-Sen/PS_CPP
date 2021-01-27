#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];
int sum[501][501];

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cin>>arr[i][j];
            if(i==0){
                sum[0][0] = arr[0][0];
            }
            else {
                if(j==0)
                    sum[i][j] = sum[i-1][j] + arr[i][j];
                else if(j==i)
                    sum[i][j] = sum[i-1][j-1] + arr[i][j];
                else{
                    sum[i][j] = max(sum[i-1][j] + arr[i][j], sum[i-1][j-1] + arr[i][j]);
                }
                        
            }
        }
    }
    
    sort(sum[n-1],sum[n-1]+n);
    cout<<sum[n-1][n-1];
    
}
