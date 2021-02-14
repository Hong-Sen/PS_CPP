#include <iostream>
using namespace std;

int main(){
    int n;
    int num = 665;
    int cnt = 0;
    cin>>n;
    while (1) {
        num++;
        string s = to_string(num);
        if(s.find("666") != -1){
            cnt++;
        }
        if(cnt == n){
            cout<<num<<"\n";
            break;
        }
    }
    return 0;
}
