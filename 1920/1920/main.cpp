#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

void BinarySearch(int *arr,int start,int end,int key){
   
    while(start<=end){
        int mid = (start+end)/2; //while문안에 있어야 시간 단축!!!
        if(arr[mid]==key){
            printf("1\n");
            return;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }
        else {
              start = mid+1;
        }
    }
        printf("0\n");
        return;
    
}
int main(){
    int n,m;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    sort(arr,arr+n);
    
    scanf("%d",&m);
    int data[m];
    for(int i=0;i<m;i++){
        scanf("%d",&data[i]);
    }
    for(int i=0;i<m;i++){
        BinarySearch(arr,0,n-1,data[i]);
    }
}
