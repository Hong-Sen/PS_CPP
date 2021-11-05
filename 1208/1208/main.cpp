#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n,s;
int arr[41];
long long cnt;
map<int, int> m;

void leftDfs(int index, int sum){
    if(index == n/2){
        m[sum]++;
        return;
    }
    leftDfs(index+1, sum + arr[index]);
    leftDfs(index+1, sum);
}

void rightDfs(int index, int sum){
    if(index == n){
        cnt += m[s-sum];
        return;
    }
    rightDfs(index+1, sum + arr[index]);
    rightDfs(index+1, sum);
}


int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    leftDfs(0, 0);
    rightDfs(n/2, 0);
    s==0 ? cout<<cnt-1 : cout<<cnt;
}
