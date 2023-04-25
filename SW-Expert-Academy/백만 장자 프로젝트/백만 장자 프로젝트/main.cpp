#include <iostream>
#include <vector>
using namespace std;

int T,N,idx;
int price[1000002];

int main() {
    cin>>T;
    while(T--) {
        cin>>N;
        long long result = 0;
        for(int i=0; i<N; i++) {
            cin>>price[i];
        }
        int maxN = price[N-1];
        for(int i=N-2; i>=0; i--) {
            if(maxN < price[i]) maxN = price[i];
            else result += maxN - price[i];
        }
        cout<<"#"<<++idx<<" "<<result<<"\n";
    }
    
}
