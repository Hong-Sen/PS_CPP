#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    string order;
    int n,input;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>order;
        
        if(order=="push"){
            cin>>input;
            q.push(input);
        }
        
        else if(order=="pop"){
            if(q.size()==0)
                cout<<"-1\n";
            else{
                cout<<q.front()<<'\n';
                q.pop();
            }
        }
        
        else if(order=="size"){
            cout<<q.size()<<'\n';
        }
        
        else if(order=="empty"){
            if(q.size()==0)
                cout<<"1\n";
            else
                cout<<"0\n";
        }
        
        else if(order=="front"){
            if(q.size()==0)
                cout<<"-1\n";
            else
                cout<<q.front()<<'\n';
        }
        
        else if(order=="back"){
            if(q.size()==0)
                cout<<"-1\n";
            else
                cout<<q.back()<<'\n';
        }
    }
}
