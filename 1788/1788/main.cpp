#include <iostream>
using namespace std;

int dp[2000001];

int fibonachi(int num){
    for (int i = 2; i <= num; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
        }
        return dp[num];
}

int main(){
    int n;
    cin>>n;
    dp[0] = 0;
    dp[1] = 1;
    int x = fibonachi(abs(n));
    if(n%2==0 && n<0)   x = -x;
    if(x > 0)   cout<<"1\n";
    else if(x == 0) cout<<"0\n";
    else    cout<<"-1\n";
    cout<<abs(x);
}
