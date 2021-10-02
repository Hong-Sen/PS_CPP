#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10002];
long long sum;
int negative;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i] < 1)  negative++;
    }
    sort(arr,arr+n);
    //0이하의 수
    for(int i=0; i<negative; i+=2){
        //홀수일 경우 남는 하나 더하기
        if(i+1 >= negative){
            sum += arr[i];
            break;
        }
        sum += max(arr[i] + arr[i+1], arr[i] * arr[i+1]);
    }
    //1이상의 수
    for(int i=n-1; i>=negative; i-=2){
        //홀수일 경우 남는 하나 더하기
        if(i-1 < negative){
            sum += arr[i];
            break;
        }
        sum += max(arr[i] + arr[i-1], arr[i] * arr[i-1]);
    }
    cout<<sum;
}
