#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        pq.push(x);
    }
    int sum = 0;
    while (1) {
        if(pq.size() == 1){
            cout<<sum<<"\n";
            break;
        }
        int tmp = pq.top();
        pq.pop();
        tmp += pq.top();
        pq.pop();
        pq.push(tmp);
        sum += tmp;
    }
}
