#include <iostream>
using namespace std;

int data[40];

int fibonacci(int x){
    if(x<2){
        if(x==0)
            data[0] = 1;
        if(x==1)
            data[1] = 1;
        return x;
    }
        if(data[x] != 0){
                return data[x];
            }
            else
            {
                return data[x] = fibonacci(x-1) + fibonacci(x-2);
            }
    
}


int main(){
    int t;
    cin>>t;
    int n;
    for(int i=0;i<t;i++){
        cin>>n;
        fibonacci(n);
        if(n==0)
            printf("%d %d\n", 1, 0);
        else if(n==1)
            printf("%d %d\n", 0, 1);
        else
        printf("%d %d\n", data[n-1], data[n]);
    }
}
