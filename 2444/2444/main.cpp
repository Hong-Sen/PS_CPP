#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<2*n-1; j++){

                if(j<n-i-1) cout<<" ";
                else if(j>=n-i-1 && j<=n+i-1)   cout<<"*";

        }
        cout<<"\n";
    }

    for(int i=n-1; i>0; i--){
        for(int j=0; j<2*n-1; j++){
            if(j<n-i) cout<<" ";
            else if(j>=n-i && j<n+i-1)   cout<<"*";
        }
        cout<<"\n";
    }
}
