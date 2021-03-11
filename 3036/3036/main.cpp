#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];

int gcd(int a, int b){
    int r;
    while(b!=0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<n; i++){
        int q = arr[0];
        cout<<q / gcd(q,arr[i])<<"/"<<arr[i] / gcd(q,arr[i])<<"\n";
    }
       
    }

