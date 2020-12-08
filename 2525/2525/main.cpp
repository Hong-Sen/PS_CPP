#include <iostream>
using namespace std;

int main(){
    int h,m,end;
    cin>>h>>m>>end;
    int hp = (m+end)/60;
    int mp = (m+end)%60;
    h = (h+hp)%24;
    m = mp;

    cout<<h<<" "<<m<<"\n";
    
}
