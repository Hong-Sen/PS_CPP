#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t,a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        int result = a;
        for(int i=2;i<=b;i++){
            result *= a;
            result %= 10;
        }
        if(result%10 == 0) cout<<"10\n";
        else cout<<result%10<<"\n";
    }
}
