#include <iostream>
using namespace std;

int arr[8][8];
int cnt;

int main(){
    for(int i=0; i<8; i++){
        for(int j=0 ;j<8; j++){
            char c;
            cin>>c;
            arr[i][j] = c;
            if(((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) && c=='F')  cnt++;
        }
    }
    cout<<cnt<<"\n";
    
}
