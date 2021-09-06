#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
string s;
int alphabet[26];
int sum;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0; j<s.length(); j++){
            alphabet[(int)(s[j]) - 'A'] += pow(10, s.length()-j-1);
        }
    }
    sort(alphabet, alphabet+26);
    int num = 9;
    for(int i=25; i>=0; i--){
        if(alphabet[i] == 0) break;
        sum += alphabet[i] * num;
        num--;
    }
    cout<<sum;
}
