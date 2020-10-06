#include <iostream>
using namespace std;

int cnt;
void hanoiCnt(int n, int from, int tmp, int to){
    cnt++;
    if(n == 1){
        return;
    }
    else{
        hanoiCnt(n-1, from, to ,tmp);
        hanoiCnt(n-1, tmp, from, to);
    }
}

void hanoi(int n, int from, int tmp, int to){

    if(n == 1){
        cout<<from<<" "<<to<<"\n";
    }
    else{
        hanoi(n-1, from, to ,tmp);
        cout<<from<<" "<<to<<"\n";
        hanoi(n-1, tmp, from, to);
    }
}

int main(){
    int n;
    cin>>n;
    hanoiCnt(n, 1, 2, 3);
    cout<<cnt<<"\n";
    hanoi(n, 1, 2, 3);
    
}
