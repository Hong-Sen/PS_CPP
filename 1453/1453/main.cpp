#include <iostream>
using namespace std;

bool visited[101];

int main(){
    int n,cnt=0;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(!visited[x]) visited[x] = true;
        else    cnt++;
    }
    cout<<cnt;
}
