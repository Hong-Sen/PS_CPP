#include <iostream>
using namespace std;

int dp(int n){
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else if (n==3)
        return 4;
    else
        return dp(n-1) + dp(n-2) + dp(n-3);
}

int main(){
    int t,n;
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>n;
        cout<<dp(n)<<"\n";
    }
}
