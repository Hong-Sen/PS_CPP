#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    map<int,int> m;
    map<int,int> tmp;
    for(int i=1; i<=20; i++)
        tmp.insert({i,0});
    int t,n;
    string s;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>s;
        if(s == "add"){
            cin>>n;
            m.insert({n,0});
        }
        else if(s == "remove"){
            cin>>n;
            if(m.find(n) != m.end())   m.erase(n);
        }
        else if(s == "check"){
            cin>>n;
            if(m.find(n) != m.end())  cout<<1<<"\n";
            else    cout<<0<<"\n";
        }
        else if(s == "toggle"){
            cin>>n;
            if(m.find(n) != m.end())   m.erase(n);
            else    m.insert({n,0});
        }
        else if(s == "all"){
            m = tmp;
        }
        else if(s == "empty"){
            m.clear();
        }
    }
    return 0;
}
