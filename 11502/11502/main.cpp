#include <iostream>
using namespace std;

int t,k;
int primeNum[1001];

int main(){
    cin>>t;
    for(int i=2; i<=1000; i++)
        primeNum[i] = i;
    // 에라토스테네스의 체
    for(int i=2; i<=1000; i++){
        if(primeNum[i] == 0)    continue;
        for(int j=i+i; j<=1000; j+=i){
            primeNum[j] = 0;
        }
    }
    while (t--) {
        cin>>k;
        bool flag = false;
        for(int i=2; i<=k; i++){
            if(flag || primeNum[i] == 0)    continue;
            for(int j=2; j<=k; j++){
                if(flag || primeNum[j] == 0)    continue;
                for(int l=2; l<=k; l++){
                    if(primeNum[l] == 0) continue;
                    if(primeNum[i] + primeNum[j] + primeNum[l] == k){
                        cout<<primeNum[i]<<" "<<primeNum[j]<<" "<<primeNum[l]<<"\n";
                        flag = true;
                        break;
                    }
                }
            }
        }
    }
}
