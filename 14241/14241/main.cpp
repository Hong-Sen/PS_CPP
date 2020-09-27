#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n,x;
    priority_queue<int> pq;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
    }
    
    int scoreSum = 0;
    
    
    while(pq.size() != 1){
        int score = pq.top();
        int slimeSize = pq.top();
        pq.pop();
        score *= pq.top();
        scoreSum += score;
        slimeSize += pq.top();
        pq.pop();
        pq.push(slimeSize);
    }
    
    cout<<scoreSum<<"\n";
    
    
}
