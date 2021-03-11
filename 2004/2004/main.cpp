#include <iostream>
#include <vector>
using namespace std;

long long divide(int n, int x){
    long long num = 0;
    for(long long i=x; i<=n; i*=x){
        num += n/i;
    }
    return num;
}


int main(){
    int n,m;
    cin>>n>>m;
    
    long long two = divide(n, 2) - (divide(m, 2) + divide(n-m, 2));
    long long five = divide(n, 5) - (divide(m, 5) + divide(n-m, 5));
    
    cout<<min(two, five);
    
}
