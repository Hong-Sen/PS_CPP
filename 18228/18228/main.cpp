#include <iostream>
#include <algorithm>
using namespace std;

int minLeft = 1000000001;
int minRight = 1000000001;
int flag = true;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x==-1){
            flag = false;
            continue;
        }
        if(flag){
            if(minLeft > x)    minLeft = x;
        }
        else{
            if(minRight > x)    minRight = x;
        }
    }
    cout<<minLeft + minRight;
}
