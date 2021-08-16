#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int max = 0;
    for(int i=1; i<=m; i++){
        string s = to_string(n*i);
        reverse(s.begin(), s.end());
        int x = stoi(s);
        if(max < x)  max = x;
    }
    cout<<max;
}
