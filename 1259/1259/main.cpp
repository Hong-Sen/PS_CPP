#include <iostream>
using namespace std;

int main(){
    string num;
    while (1) {
        cin>>num;
        if(num == "0")
            break;
        bool flag = true;
        for(int i=0;i<num.size()/2;i++){
            if(num[i]!=num[num.size()-i-1])
                flag = false;
        }
        if(flag==true)
            cout<<"yes"<<'\n';
        else
            cout<<"no"<<'\n';
        
        }
}
