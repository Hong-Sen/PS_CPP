#include <iostream>
using namespace std;

int main(){
    int n,sum=0;
    cin>>n;
    bool flag = false;
    int arr[1001];
    int input = 0;
    int back = 2;
    for(int i=0; i<n ;i++){
        cin>>input;
        if(input==0 && back ==2){
            back = 0;
            sum++;
        }
        else if(input==1 && back==0){
            back=1;
            sum++;
        }
        else if(input==2 && back==1){
            back=2;
            sum++;
        }
    }
    cout<<sum<<"\n";
}
