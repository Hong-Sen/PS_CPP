#include <cstdio>
#include <algorithm>
using namespace std;

int arr[10001]; //전역변수로 빼기!! 전역변수는 자동으로 0으로 초기화됌.

int main(){
    int n,input;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&input);
        arr[input]++;
    }
    
    for(int i=0;i<10001;i++){
        if(arr[i]!=0){
            while(arr[i]!=0){
                printf("%d\n",i);
                arr[i]--;
                
            }
        }
    } 
}
