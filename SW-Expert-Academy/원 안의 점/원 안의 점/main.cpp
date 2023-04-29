// 23:00
#include <iostream>
using namespace std;

int T,N,idx;

int main() {
    cin>>T;
    while(T--) {
        cin>>N;
        long long sum = 0;
        for(int i=N; i>=0; i--) {
            for(int j=N; j>=0; j--) {
                if(i * i + j * j <= N*N) {
                    sum += j+1;
                    break;
                }
            }
        }
        sum = sum * 4 - (N*4) - 3;
        cout<<"#"<<++idx<<" "<<sum<<"\n";
    }
}
