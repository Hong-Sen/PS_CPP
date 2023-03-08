#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[101];
int Plus, Minus, Multiple, Divide;
int maxValue = -1000000001;
int minValue = 1000000001;

void dfs(int result, int idx, int p, int mi, int mu, int d) {
    if(idx == N) {
        maxValue = max(maxValue, result);
        minValue = min(minValue, result);
        return;
    }
    if(p > 0) dfs(result + arr[idx], idx+1, p-1, mi, mu, d);
    if(mi > 0) dfs(result - arr[idx], idx+1, p, mi-1, mu, d);
    if(mu > 0) dfs(result * arr[idx], idx+1, p, mi, mu-1, d);
    if(d > 0) dfs(result / arr[idx], idx+1, p, mi, mu, d-1);
}
int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }
    cin>>Plus>>Minus>>Multiple>>Divide;
    
    dfs(arr[0], 1, Plus, Minus, Multiple, Divide);
    
    cout<<maxValue<<"\n"<<minValue<<"\n";
}
