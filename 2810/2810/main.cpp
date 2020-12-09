//컵의수가 아니라 컵홀더를 사용하는 사람의 수!!!
#include <iostream>
using namespace std;

int main(){
    int n,cnt=1,L=0;
    bool flag = true;
    cin>>n;
    for(int i=0; i<n; i++){
        char c;
        cin>>c;
        if(c=='S')    cnt++;
        else{
            L++;
            if(L==2){
                cnt++;
                L=0;
            }
        }
    }
    cout<<min(cnt, n)<<"\n";
 
    
}
