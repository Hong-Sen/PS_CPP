#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    priority_queue<long long>pq;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq.push(x);
    }
    
    for(int i=0;i<n-k;i++){
        pq.pop();
    }
   
    
    cout<<pq.top()<<"\n";
}
