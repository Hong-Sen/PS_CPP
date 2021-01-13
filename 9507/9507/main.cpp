#include <iostream>
using namespace std;

int t,n;
long long fibo[68];

long long fibonacci(int a){
    if(a<=1)    return 1;
    else if(a==2)   return 2;
    else if(a==3)   return 4;
    else{
        if(fibo[a] == 0){
            fibo[a] = fibonacci(a-1) + fibonacci(a-2) + fibonacci(a-3) + fibonacci(a-4);
            return fibo[a];
        }
        else{
            return fibo[a];
        }
    }
    
}

int main(){
    cin>>t;
    fibo[1] = 1;
    fibo[2] = 2;
    fibo[3] = 4;
    
    for(int i=0; i<t; i++){
        cin>>n;
        cout<<fibonacci(n)<<"\n";
    }
}
