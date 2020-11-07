#include <iostream>
using namespace std;

bool isSqrt[1000001];

int main(){
    long long min,max;
    int cnt = 0;
    cin>>min>>max;
    
    for(long long i=2; i*i<=max ; i++){
        long long begin = min/ (i*i);
        if(begin * i * i != min)    begin++;
        for(long long j = begin; i*i*j <= max; j++){
            isSqrt[i*i*j - min] = true;
        }
    }
    for(int i=0; i<max-min+1; i++){
        if(!isSqrt[i])  cnt++;
    }
    
    cout<<cnt<<"\n";
}
