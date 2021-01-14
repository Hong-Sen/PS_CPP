#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, time = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    cin>>n;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        pq.push(make_pair(a, b));
    }

    for(int i=0; i<n; i++){
        if(time < pq.top().first){
            time = pq.top().first + pq.top().second;
            pq.pop();
        }
        else{
            time += pq.top().second;
            pq.pop();
        }
    }
    cout<<time;
}
