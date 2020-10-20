#include <iostream>
using namespace std;

int main(){
    int n,f;
    cin>>n>>f;
    n = n - n%100;
    while(1){
        if(n % f == 0){
            if((n % 100) / 10 == 0)
                cout<<"0"<<n%100<<"\n";
            else
                cout<<n%100<<"\n";
            break;
        }
        n++;
    }
}
