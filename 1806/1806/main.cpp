// 투포인터 시간 복잡도 O(N)
#include <iostream>
using namespace std;

int n,s;
int arr[100001];
int length = 100001;
int sum;

int main(){
    cin>>n>>s;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int start = 0, end = 0;
    sum = arr[0];
    while (start <= end && end < n) {
        if(sum >= s) length = min(length,end-start+1);
        if(sum < s) sum += arr[++end];
        else sum -= arr[start++];
    }
    length == 100001 ? cout<<0 : cout<<length;
}
