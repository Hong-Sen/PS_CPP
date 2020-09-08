#include <cstdio>
#include <algorithm>
using namespace std;

int mylower_bound(int arr[], int n, int key){
    int start = 0;
    int end = n;
    int mid = n;
    while(end-start>0){
         mid = (start+end)/2;
        if(arr[mid] < key)
            start = mid + 1;
        else
            end = mid;
    }
    return end;
}
int myupper_bound(int arr[], int n, int key){
    int start = 0;
    int end = n;
    int mid = n;

    while(end-start>0){
        mid = (start+end)/2;
        if(arr[mid] <= key)
            start = mid+1;
        else
            end = mid;
    }
    return end;
}
int main(){
    int M;
    scanf("%d",&M);
    int m[M];
    for(int i=0;i<M;i++){
        scanf("%d",&m[i]);
    }
    int N;
    scanf("%d",&N);
    int n[N];
    for(int i=0;i<N;i++){
        scanf("%d",&n[i]);
    }
    
    sort(m,m+M);
    
    for(int i=0;i<N;i++){
        printf("%d ",myupper_bound(m, M, n[i]) - mylower_bound(m, M, n[i]));
    }
    printf("\n");
}
