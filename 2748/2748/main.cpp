#include <iostream>
using namespace std;

long long data[91];

long long fibonachi(int n){
    if(n<2){
        data[n] = n;
    }
    else if(data[n]==0)
        data[n] = fibonachi(n-1) + fibonachi(n-2);
    return data[n];
}

int main(){
    int n;
    cin>>n;
    cout<<fibonachi(n)<<"\n";

}
