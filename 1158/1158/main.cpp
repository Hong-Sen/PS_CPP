#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    queue<int> q;
    vector<int> result;
    for(int i=1; i<=n; i++)
        q.push(i);
    while (!q.empty()) {
        for(int i=0; i<k-1; i++){
            q.push(q.front());
            q.pop();
        }
        result.push_back(q.front());
        q.pop();
    }
    cout<<"<";
    for(int i=0; i<result.size(); i++){
        if(i==result.size()-1)  cout<<result[i]<<">";
        else    cout<<result[i]<<", ";
    }
   
}
