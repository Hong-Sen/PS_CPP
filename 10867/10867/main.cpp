#include <iostream>
#include <queue>
using namespace std;

bool arr[2002];
priority_queue<int, vector<int>, greater<int>> q;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(!arr[x+1000]){
            q.push(x);
            arr[x+1000] = true;
        }
    }
    
    while (!q.empty()) {
        cout<<q.top();
        if(q.size() != 1)   cout<<" ";
        q.pop();
    }
    
}
