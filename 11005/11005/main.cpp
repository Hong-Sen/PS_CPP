#include <iostream>
using namespace std;

int N,B;

int main() {
    cin>>N>>B;
    string s;
    while(N != 0) {
        int rest = N % B;
        if(rest > 9) s = char(rest + 55) + s;
        else s = to_string(rest) + s;
        N /= B;
    }
    
    cout<<s;
}
