#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> schedule;
priority_queue<int, vector<int>, greater<int>> room;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int order, start, finish;
    for(int i=0; i<n; i++){
        cin>>order>>start>>finish;
        schedule.push({start,finish});
    }
    room.push(schedule.top().second);
    schedule.pop();
    
    for(int i=1; i<n; i++){
        if(schedule.top().first >= room.top()){
            room.pop();
            room.push(schedule.top().second);
        }
        else{
            room.push(schedule.top().second);
        }
        schedule.pop();
    }
    cout<<room.size();
    return 0;
}
