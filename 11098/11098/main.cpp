#include <iostream>
#include <string>
using namespace std;

int main(){
    int t,p;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>p;
        int maxValue = 0;
        string maxName = "";
        for(int j=0; j<p; j++){
            int value;
            string name;
            cin>>value>>name;
            if(value > maxValue){
                maxValue = value;
                maxName = name;
            }
        }
        cout<<maxName<<"\n";
    }
}
