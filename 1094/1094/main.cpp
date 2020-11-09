//이진법으로 나타냈을 때 1이 몇개 들어가는지와 동일한 문제!!
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt = 0;
    while (n != 0) {
        if(n%2 == 1)    cnt++;
        n /= 2;
    }
    cout<<cnt<<"\n";
}
