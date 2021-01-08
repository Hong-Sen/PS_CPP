#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int sum = 0;
    int min = pow(ceil(sqrt(n)),2);
    for(int i=ceil(sqrt(n)); i<=sqrt(m); i++){
        sum += pow(i, 2);
    }
    if(sum==0)  cout<<-1;
    else    cout<<sum<<"\n"<<min;
}
