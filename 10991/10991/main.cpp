#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n+i; j++){
            if(j>=n-1-i && j<=n-1+i){
                if(n%2==0){
                    if(i%2==0){
                        if(j%2==1)  cout<<"*";
                        else    cout<<" ";
                    }
                    else{
                        if(j%2==0)  cout<<"*";
                        else    cout<<" ";
                    }
                }
                else{
                    if(i%2==0){
                        if(j%2==0)  cout<<"*";
                        else    cout<<" ";
                    }
                    else{
                        if(j%2==1)  cout<<"*";
                        else    cout<<" ";
                    }
                }
                
            }
            else    cout<<" ";
        }
        cout<<"\n";
        
    }
}
