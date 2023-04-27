#include <iostream>
using namespace std;

int N;

int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        string s = to_string(i);
        bool flag = false;
        for(char c: s) {
            if(c == '3' || c == '6' || c == '9') {
                flag = true;
                cout<<"-";
            }
        }
        if(!flag) cout<<i<<" ";
        else cout<<" ";
    }
}
