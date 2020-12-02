#include <iostream>
using namespace std;

int main(){
    int m,d;
    cin>>m>>d;
    if(m<2){
        cout<<"Before\n";
        return 0;
    }
    else if(m==2){
        if(d<18){
            cout<<"Before\n";
            return 0;
        }
        else if(d==18){
            cout<<"Special\n";
            return 0;
        }
        else{
            cout<<"After\n";
            return 0;
        }
    }
    else{
        cout<<"After\n";
        return 0;
    }
    
}
