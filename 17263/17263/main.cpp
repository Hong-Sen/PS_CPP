#include <iostream>
using namespace std;

int m = 0;

int max(int n){
    m = (m < n) ? n : m;
    return m;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        max(x);
    }
    cout<< m;
}
