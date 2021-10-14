#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int N,M;
string factorial[MAX][MAX];

string bigNumAdd(string n1, string n2){
    long long sum = 0;
    string result;
    while (!n1.empty() || !n2.empty() || sum) {
        if(!n1.empty()){
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if(!n2.empty()){
            sum += n2.back() - '0';
            n2.pop_back();
        }
        result.push_back(sum%10 + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int m){
    if(m==0 || n==m){
        return "1";
    }
    
    if(factorial[n][m] != "") return factorial[n][m];
    factorial[n][m] = bigNumAdd(combination(n-1, m-1), combination(n-1, m));
    return factorial[n][m];
}

int main(){
    cin>>N>>M;
    cout<<combination(N, M);
}
