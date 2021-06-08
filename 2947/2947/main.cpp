#include <iostream>
using namespace std;

int wood[5] = {1,2,3,4,5};
int arr[5];

void printArr(){
    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

bool cmp(){
    for(int i=0; i<5; i++){
        if(arr[i] != wood[i])   return false;
    }
    return true;
}

int main(){
    for(int i=0; i<5; i++){
        cin>>arr[i];
    }

    bool flag = true;
    while (flag) {
        for(int i=0; i<5; i++){
            if(i==4){
                if(cmp())   flag = false;
            }
            else{
                if(arr[i] > arr[i+1]){
                    swap(arr[i], arr[i+1]);
                    printArr();
                }
            }
        }
    }
    return 0;
}
