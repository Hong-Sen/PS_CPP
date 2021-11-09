#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100001][3];
int dpMax[2][3]; // dpMax[0][n] = 바로 전 배열, dp[1][n] = 현재 배열
int dpMin[2][3];

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }
    dpMax[0][0] = dpMin[0][0] = arr[0][0];
    dpMax[0][1] = dpMin[0][1] = arr[0][1];
    dpMax[0][2] = dpMin[0][2] = arr[0][2];
    
    for(int i=1; i<N; i++){
        dpMax[1][0] = arr[i][0] + max(dpMax[0][0], dpMax[0][1]);
        dpMax[1][1] = arr[i][1] + max(dpMax[0][0], max(dpMax[0][1],dpMax[0][2]));
        dpMax[1][2] = arr[i][2] + max(dpMax[0][1], dpMax[0][2]);
        
        dpMin[1][0] = arr[i][0] + min(dpMin[0][0], dpMin[0][1]);
        dpMin[1][1] = arr[i][1] + min(dpMin[0][0], min(dpMin[0][1], dpMin[0][2]));
        dpMin[1][2] = arr[i][2] + min(dpMin[0][1], dpMin[0][2]);
        
        // 메모리 초과 방지용 copy
        for(int j=0; j<3; j++){
            dpMax[0][j] = dpMax[1][j];
            dpMin[0][j] = dpMin[1][j];
        }
    }
    
    cout<<max(dpMax[0][0],max(dpMax[0][1],dpMax[0][2]))<<" "<<min(dpMin[0][0],min(dpMin[0][1],dpMin[0][2]));
}
