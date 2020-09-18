#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp{
    bool operator() (pair<int, int> p1, pair<int, int> p2){
        if(p1.second != p2.second)
            return p1.second > p2.second;
        return p1.first > p2.first;
    }
};

int main(){
    int n;
    cin>>n;
    priority_queue<pair<int,int>, vector<pair<int, int>>, cmp > pq;
    
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        pq.push({x,y});
    }
    
    while (!pq.empty()) {
        cout<<pq.top().first<<" "<<pq.top().second<<"\n";
        pq.pop();
    }
}
