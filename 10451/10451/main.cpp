#include <iostream>
#include <cstring>
using namespace std;

int t,n;
int arr[1001];
bool visited[1001];
int cnt;

void findCycle(int start, int num){
    if(start == num){
        cnt++;
        return;
    }
    visited[num] = true;
    findCycle(start, arr[num]);
}

int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        for(int j=1; j<=n; j++){
            cin>>arr[j];
        }
        memset(visited, false, sizeof(visited));
        cnt = 0;
        for(int k=1; k<=n; k++){
            if(!visited[k]){
                visited[k] = true;
                findCycle(k, arr[k]);
            }
        }
        cout<<cnt<<"\n";
    }
}
