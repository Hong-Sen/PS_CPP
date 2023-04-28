// 17:27
#include <iostream>
using namespace std;

int N;
int height[1001];
int cnt;

void dfs(int x) {
    if(height[x] == 0) return;
    int leftGap1 = height[x] - height[x-1], leftGap2 = height[x] - height[x-2];
    int rightGap1 = height[x] - height[x+1], rightGap2 = height[x] - height[x+2];
    if(leftGap1 > 0 && leftGap2 > 0 && rightGap1 > 0 && rightGap2 > 0) {
        cnt += min(min(leftGap1, leftGap2), min(rightGap1, rightGap2));
    }
}

int main(){
    for(int t=1; t<=10; t++) {
        cin>>N;
        cnt = 0;
        for(int i=0; i<N; i++) {
            cin>>height[i];
        }
        for(int i=2; i<N-2; i++) {
            dfs(i);
        }
        cout<<"#"<<t<<" "<<cnt<<"\n";
    }
}
