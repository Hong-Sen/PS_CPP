#include <iostream>
#include <cmath>
using namespace std;

int n;
long long sum;

int main() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        int tmp = n/i;
        tmp *= i;
        sum += tmp;
    }
    
    cout<<sum<<"\n";
}
