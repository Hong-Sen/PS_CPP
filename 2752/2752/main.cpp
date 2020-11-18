#include <iostream>
#include <queue>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(a);
    q.push(b);
    q.push(c);
    
    cout<<q.top()<<" ";
    q.pop();
    cout<<q.top()<<" ";
    q.pop();
    cout<<q.top()<<"\n";
    
}
