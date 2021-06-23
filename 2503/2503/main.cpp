#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int t;
int n, strike, ball;
bool arr[1000];
int result;

int main(){
    cin>>t;
    memset(arr, true, sizeof(arr));
    for(int i=123; i<1000; i++){
        string tmp = to_string(i);
        if(tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
            arr[i] = false;
        if(tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[2] == tmp[0])
            arr[i] = false;
    }
    
    for(int i=0; i<t; i++){
        cin>>n>>strike>>ball;
        for(int j=123; j<1000; j++){
            if(!arr[j]) continue;
            string s1 = to_string(n);
            string s2= to_string(j);
            int strikeCnt = 0;
            int ballCnt = 0;
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    if(s1[k] == s2[l] && k == l)    strikeCnt++;
                    if(k != l && s1[k] == s2[l])     ballCnt++;
                }
            }
            if(strike != strikeCnt || ball != ballCnt){
                arr[j] =false;
            }
        }
    }
    for(int i=123; i<1000; i++){
        if(arr[i]) result++;
    }
    cout<<result<<"\n";
}
