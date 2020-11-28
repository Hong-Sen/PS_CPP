#include <iostream>

using namespace std;

int main(){
    int n;
    int sum = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        int st,ap;
        cin>>st>>ap;
        int x = st;
        while(1){
           int rest = ap/st;
            if(rest == 0){
                if(st - x == 0) st = x;
                else    st -= x;
                break;
            }
            st += x;
        }
        sum += ap%st;
    }

    cout<<sum<<"\n";
}
