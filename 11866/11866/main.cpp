#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N,K;
    cin>>N;
    cin>>K;
    
    queue<int> q;
 
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    cout<<"<";
    while (1) {
        if(q.size()==1){
            cout<<q.front();
            break;
        }
        for(int i=0;i<K-1;i++){
            q.push(q.front());
            q.pop();
        }
        cout<<q.front()<<", ";
        q.pop();
    }
    cout<<">\n";
    
}
