#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> primeN;
bool arr[4000001];
int sum;
int cnt;

int main(){
    cin>>n;
    if(n == 1){
        cout<<"0";
        return 0;
    }
    // 에라토스테네스의 체
    for(int i=2; i<=n; i++){
        if(arr[i])  continue;
        for(int j=i+i; j<=n; j+=i){
            arr[j] = true; // not prime number
        }
    }
    for(int i=2; i<=n; i++){
        if(!arr[i]) primeN.push_back(i);
    }
    
    int start = 0, end = 0;
    sum = primeN[start];
    int pSize = primeN.size();
    while (end < pSize) {
        if(sum == n){
            cnt++;
        }
        if(sum >= n){
            sum -= primeN[start];
            start++;
        }
        if(sum < n){
            end++;
            sum += primeN[end];
        }
    }
    cout<<cnt<<"\n";
}
