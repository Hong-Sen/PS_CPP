#include <iostream>
using namespace std;

int solve(string s1, string s2){
    int cntW = 0;
    int cntB = 0;
    for(int i=0; i<s1.length(); i++){
        if(s1[i] != s2[i]){
            if(s1[i] == 'W')    cntW++;
            else    cntB++;
        }
    }
    int cnt = max(cntB, cntW);
    return cnt;
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        cout<<solve(s1, s2)<<"\n";
    }
}
