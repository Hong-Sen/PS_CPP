#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int plus = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        if(k==1)    plus++;
        else if(k==0)   plus=0;
        sum += plus;
    }
    cout<<sum<<"\n";
}
