#include <iostream>
#define MAX(x,y) (x>y ? x: y)
#define MIN(x,y) (x>y ? y: x)
using namespace std;

int op[4];
int arr[14];
int maxResult = -1000000001,minResult = 1000000001;

void solve(int plus,int minus,int mul,int div,int n,int sum,int index){
    if(index==n){
        maxResult = MAX(maxResult, sum);
        minResult = MIN(minResult, sum);
    }
    if(plus>0)  solve(plus-1, minus, mul, div, n, sum+arr[index], index+1);
    if(minus>0)  solve(plus, minus-1, mul, div, n, sum-arr[index], index+1);
    if(mul>0)  solve(plus, minus, mul-1, div, n, sum*arr[index], index+1);
    if(div>0)  solve(plus, minus, mul, div-1, n, sum/arr[index], index+1);
    
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<4; i++){
        cin>>op[i];
    }
    solve(op[0], op[1], op[2], op[3], n, arr[0], 1);
    cout<<maxResult<<"\n"<<minResult<<"\n";
}
