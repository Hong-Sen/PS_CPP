#include<iostream>
using namespace std;

int k,S[13],result[6];

void lottery(int x,int d){
    if(d==6){
        for(int i=0;i<6;i++){
            cout<<result[i]<<" ";
        }
        cout<<'\n';
    }
    for(int i=x;i<k;i++){
        result[d] = S[i];
        lottery(i+1,d+1);
    }
    
}

int main(){
    
    while(1){
        cin>>k;
        if(k==0)
            break;
        for(int i=0;i<k;i++)
            cin>>S[i];
        lottery(0,0);
        cout<<'\n';
    }
    return 0;
}

