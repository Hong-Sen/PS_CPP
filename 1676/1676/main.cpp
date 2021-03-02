#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long num = 1;
    int cnt = 0;
    for(int i=2; i<=n; i++){
        if(i % 125 == 0)    cnt += 3;
        else if(i % 25 == 0) cnt += 2;
        else if(i % 5 == 0)   cnt += 1;
  
    }
    cout<<cnt;
}
