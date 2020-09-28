#include <iostream>
#include <queue>
using namespace std;
typedef long long int lld;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    cin>>n;
    priority_queue<lld> pq;
    
    for(int i=0;i<n*n;i++){
        int x;
        cin>> x;
        pq.push(-x);
        if(pq.size() > n){
            pq.pop();
        }
    }
    cout<<-pq.top()<<"\n";
}
