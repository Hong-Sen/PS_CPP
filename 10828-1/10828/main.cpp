#include <iostream>
#include <stack>
#define MAX_SIZE 10000
using namespace std;

stack<int> s;
int N;

int main(){
  
    cin>>N;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        if(str=="push"){
            int n;
            cin>>n;
            s.push(n);
        }
            
        if(str=="pop"){
            if(s.empty())
                cout<<"-1"<<'\n';
            else{
                cout<<s.top()<<'\n';
                s.pop();
            }
                
        }
            
        
        if(str=="size")
            cout<<s.size()<<'\n';
        
        if(str=="empty"){
            
            if(s.empty())
                cout<<"1"<<'\n';
            else
                cout<<"0"<<'\n';
            
        }
           
        if(str=="top"){
            if(s.empty())
                cout<<"-1"<<'\n';
           else
               cout<<s.top()<<'\n';

        }

    }
    return 0;
}
