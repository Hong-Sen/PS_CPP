// 12:49
#include <iostream>
using namespace std;

int N,X,sum,total,day = 1;
int arr[250001];

int main() {
    cin>>N>>X;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
        if(i < X) sum += arr[i];
    }
    total = sum;
    for(int i=0; i<N-X; i++) {
        sum -= arr[i];
        sum += arr[i+X];
        if(total == sum) day++;
        else if(total < sum) {
            day = 1;
            total = sum;
        }
    }
    if(total == 0) cout<<"SAD";
    else cout<<total<<"\n"<<day;
}
