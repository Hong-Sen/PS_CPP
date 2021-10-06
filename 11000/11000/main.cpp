#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int s,t;
priority_queue<int,vector<int>,greater<int>> room;

int main(){
    cin>>n;
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
    for(int i=0; i<n; i++){
        cin>>s>>t;
        pq.push({s,t});
    }
    
    room.push(pq.top().second);
    pq.pop();
    while (!pq.empty()) {
        if(pq.top().first >= room.top()){
            room.pop();
        }
        room.push(pq.top().second);
        pq.pop();
    }
       
    cout<<room.size();
}
