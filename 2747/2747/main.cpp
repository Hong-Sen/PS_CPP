#include <iostream>
using namespace std;

int result[46];

int fibonachi(int n){
   if(n <= 2)
       return 1;
    if(result[n] != 0)
        return result[n];
    else{
        result[n] = fibonachi(n-1) + fibonachi(n-2);
        return result[n];
    }
}
int main(){
    int n;
    cin>>n;
    cout<<fibonachi(n)<<"\n";
}
