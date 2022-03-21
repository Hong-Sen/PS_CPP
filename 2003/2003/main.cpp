#include <iostream>
using namespace std;

int n,m;
int arr[10001];
int sum;
int cnt;

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int start = 0, end = 0;
    while (end <= n) {
        if(sum >= m) sum -= arr[start++];
        else if(sum < m) sum += arr[end++];
        if(sum == m)    cnt++;
    }
    cout<<cnt;
}
