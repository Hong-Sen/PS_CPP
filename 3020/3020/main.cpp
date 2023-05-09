#include <iostream>
using namespace std;

int N,H;
int top[500001];
int bottom[500001];
int sum[500001];
int cnt;
int minValue = 987654321;

int main() {
    cin>>N>>H;
    for(int i=0; i<N/2; i++) {
        int low, high;
        cin>>low>>high;
        bottom[low]++;
        top[H+1-high]++;
    }
    
    for(int i=H-1; i>0; i--) {
        bottom[i] += bottom[i+1];
    }
    
    for(int i=1; i<=H; i++) {
        top[i] += top[i-1];
        sum[i] = top[i] + bottom[i];
        if(sum[i] < minValue) {
            cnt = 1;
            minValue = sum[i];
        }
        else if(sum[i] == minValue) {
            cnt++;
        }
    }
    cout<<minValue<<" "<<cnt;
}
