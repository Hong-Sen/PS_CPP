#include <iostream>
#include <cmath>
using namespace std;

int Mod = 1234567891;

int main(){
    int l;
    string s;
    cin>> l;
    cin>>s;
    long long sum = 0;
    
    for(int i=0;i<l;i++){
        int num = (int)(s.at(i) - 96);
        sum += num * pow(31, i);
    }
    
    cout<< sum<<"\n";
}
