#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N;
    cin>>N;
    queue<int>que;
    string input;
    int n;

    for(int i=0;i<N;i++){
        cin>>input;
        
        if(input=="push"){
            cin>>n;
            que.push(n);
        }
        
        if(input=="pop"){
            if(que.empty())
                cout<<"-1\n";
            else{
                cout<<que.front()<<"\n";
                que.pop();
            }
                
        }
        
        if(input=="front"){
            if(que.empty())
                cout<<"-1\n";
            else
                cout<<que.front()<<"\n";
        }
        
        if(input=="back"){
            if(que.empty())
                cout<<"-1\n";
            else
               cout<<que.back()<<"\n";
        }
        
        if(input=="empty"){
            cout<<que.empty()<<"\n";
        }
        
        if(input=="size"){
            cout<<que.size()<<"\n";
            
        }
    }
    return 0;
}
