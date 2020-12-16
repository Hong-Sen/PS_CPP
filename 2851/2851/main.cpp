#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int mush[10];
    int sum1=0,sum2=0;
    for(int i=0; i<10; i++){
        cin>>mush[i];
    }
    for(int i=0; i<10; i++){
        sum1 += mush[i];
        if(sum1 == 100){
            cout<<100<<"\n";
            break;
        }
        else if (sum1 > 100){
            sum2 = sum1 - mush[i];
            if(abs(sum2-100) < (sum1-100)){
                cout<<sum2<<"\n";
                break;
            }
            else{
                cout<<sum1<<"\n";
                break;
            }
        }
    }
    if(sum1<100)    cout<<sum1<<"\n";
    
}
