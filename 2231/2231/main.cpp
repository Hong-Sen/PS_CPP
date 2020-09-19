#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    for(int i=1;i<n;i++){
         int sum = i;
         int d = i;
        while(d!=0){
            sum += d%10;
            d /= 10;
        }
        if(sum == n){
            cout<<i<<"\n";
            return 0;
        }
    }
    
    cout<<"0\n";
    return 0;
    
}
