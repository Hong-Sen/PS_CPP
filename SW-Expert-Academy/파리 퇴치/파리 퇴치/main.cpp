// 22:05
#include <iostream>
using namespace std;

int T,N,M,idx;
int arr[16][16];
int sum[16][16];

int caculateMax() {
    sum[0][0] = 0;
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            sum[0][0] += arr[i][j];
        }
    }
    int result = sum[0][0];
    for(int i=0; i<N-M+1; i++) {
        for(int j=0; j<N-M+1; j++) {
            if(j==0) {
                if(i==0) continue;
                sum[i][j] = sum[i-1][j];
                for(int k=0; k<M; k++) {
                    sum[i][j] -= arr[i-1][j+k];
                    sum[i][j] += arr[i+M-1][j+k];
                }
            }
            else {
                sum[i][j] = sum[i][j-1];
                for(int k=0; k<M; k++) {
                    sum[i][j] -= arr[i+k][j-1];
                    sum[i][j] += arr[i+k][j+M-1];
                }
            }
            result = max(result, sum[i][j]);
        }
    }
    return result;
}

int main() {
    cin>>T;
    while (T--) {
        cin>>N>>M;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin>>arr[i][j];
            }
        }
        cout<<"#"<<++idx<<" "<<caculateMax()<<"\n";
    }
}
