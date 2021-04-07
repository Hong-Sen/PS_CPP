#include <iostream>
using namespace std;
int main(){
    int t,n,m;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n>>m;
        int tmp = 2*m - n;
        cout<<tmp<<" "<<m-tmp<<"\n";
    }
}
