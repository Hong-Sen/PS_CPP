#include <iostream>
#include <string>
#include <map>
using  namespace std;

int main(){
    int t,n;
    string dress,kind;
    
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        map<string, int> m;
        for(int j=0;j<n;j++){
            cin>>dress>>kind;
            m[kind] ++;
        }
        int cnt = 1;
        for(auto j=m.begin();j!=m.end();j++){
            cnt *= (j->second+1);
        }
    
        cout<<cnt-1<<"\n";
    }
}
