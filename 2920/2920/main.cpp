#include <iostream>
using namespace std;

int main(){
    int num[8];
    int flag1 = 1;
    int flag2 = 1;
    for(int i=0;i<8;i++){
        cin>>num[i];
    }
    for(int i=0;i<8;i++){
        if(num[i]!=i+1){
            flag1 = 0;
            break;
        }
    }
    for(int i=0;i<8;i++){
        if(num[i]!=8-i){
            flag2 = 0;
            break;
        }
    }
    
    if(flag1==1)
        cout<<"ascending"<<'\n';
    else if(flag2==1)
        cout<<"descending"<<'\n';
    else
        cout<<"mixed"<<'\n';
    
}
