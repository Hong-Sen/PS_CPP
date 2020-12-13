#include <iostream>
using namespace std;

int main(){
    int sum;
    cin>>sum;
    for(int i=0; i<9; i++){
        int x;
        cin>>x;
        sum -= x;
    }
    cout<<sum<<"\n";
    
}
