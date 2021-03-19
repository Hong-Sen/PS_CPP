#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    long long sum = 0;
    for(int i=0; i<t; i++){
        int hp,mp,att,def,h,m,a,d;
        cin>> hp>>mp>>att>>def>>h>>m>>a>>d;
        hp = max(1,hp+h);
        mp = max(1,mp+m);
        att = max(0,att+a);
        def += d;
      
        cout<<hp + 5*mp + 2*(att+def)<<"\n";
    }
}
