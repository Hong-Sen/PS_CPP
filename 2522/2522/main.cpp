#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<2*n-1; i++){
        for(int j=0; j<n; j++){
            if(i<n){
                if(j<n-i-1)    cout<<" ";
                else    cout<<"*";
                    }
            else{
                if(j>i-n)   cout<<"*";
                else    cout<<" ";
            }

        }
        cout<<"\n";
        
    }
}
