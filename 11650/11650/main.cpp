#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp{
    bool operator() (pair<int, int> p1, pair<int, int> p2){
        if(p1.first != p2.first)
            return p1.first > p2.first;
        else
            return p1.second > p2.second;
    }
};

int main(){
    int n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        pq.push({x,y});
    }
    
    while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second<<"\n";
        pq.pop();
    }
    
}
