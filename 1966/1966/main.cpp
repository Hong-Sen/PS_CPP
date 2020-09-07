#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int  n,m;
        cin>>n>>m;
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            q.push(pair<int, int>(num,j));
            pq.push(num);
        }
        int cnt = 0;
        while(1){
            
            if(q.front().first== pq.top()){
                cnt++;
                if(q.front().second == m){
                    cout<<cnt<<'\n';
                    break;
                }
                else{
                    q.pop();
                    pq.pop();
                }
            }
            
            else{
                q.push(q.front());
                q.pop();
            }
        }
        
    }
}
