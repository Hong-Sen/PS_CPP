#include <iostream>
using namespace std;

int n;
long long road[100001];
long long oil[100001];
long long cost[100001];

int main(){
    cin>>n;
    for(int i=0; i<n-1; i++)
        cin>>road[i];
    for(int i=0; i<n; i++)
        cin>>oil[i];
    
    cost[0] = road[0] * oil[0];
    long long min = oil[0];
    for(int i=1; i<n; i++){
        if(oil[i] < min){
            min = oil[i];
        }
        cost[i] = min * road[i] + cost[i-1];
    }
    cout<<cost[n-1];
}
