#include <iostream>
#include <deque>
using namespace std;

int main(){
    
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int t,x;
    string s;
    deque<int> dq;
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>s;
        
        if(s=="push_front"){
            cin>>x;
            dq.push_front(x);
        }
        
        if(s=="push_back"){
            cin>>x;
            dq.push_back(x);
        }
        
        if(s=="pop_front"){
            if(dq.empty())
                cout<<"-1\n";
            else{
                cout<<dq.front()<<"\n";
                dq.pop_front();
            }
        }
        
        if(s=="pop_back"){
            if(dq.empty())
                cout<<"-1\n";
            else{
                cout<<dq.back()<<"\n";
                dq.pop_back();
            }
        }
        
        if(s=="size"){
            cout<<dq.size()<<"\n";
        }
        
        if(s=="empty"){
            if(dq.empty())
                cout<<"1\n";
            else
                cout<<"0\n";
        }
        
        
        if(s=="front"){
            if(dq.empty())
                cout<<"-1\n";
            else{
                cout<<dq.front()<<"\n";
            }
        }
        
        if(s=="back"){
            if(dq.empty())
                cout<<"-1\n";
            else{
                cout<<dq.back()<<"\n";
            }
        }
        
        
    }
}
