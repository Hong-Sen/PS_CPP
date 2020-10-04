#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n,x;
    cin>>n;
    priority_queue<pair<int, int>> pq;
    
    for(int i=0;i<n;i++){
        cin>>x;
        if(!x && pq.empty()){
            cout<<"0\n";
        }
        else if(!x){
            cout<<-pq.top().second<<"\n";
                        pq.pop();
        }
        else{
            pq.push({-abs(x),-x});
        }
    }
}
