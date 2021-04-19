#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i%2 == 0)
                (j%2==0) ? cout<<"*" : cout<<".";
            else
                (j%2==0) ? cout<<"." : cout<<"*";
        }
        cout<<"\n";
    }
}
