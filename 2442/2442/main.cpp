#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=n; i>0; i--){
        for(int j=0; j<2*n-1; j++){
            if(j<i-1)  cout<<" ";
            else if(j<2*n-i)    cout<<"*";
        }
        cout<<"\n";
    }
}
