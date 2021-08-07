#include <iostream>
using namespace std;

long long solution(long long a, long long b, long long c){
    if(b == 1){
        return a%c;
    }
    else if(b % 2 == 0){
        return solution(a,b/2,c)*solution(a,b/2,c) % c;
    }
    else{
        return (solution(a,b/2,c)*solution(a,b/2+1,c)) % c;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long a,b,c;
    cin>>a>>b>>c;
    cout<<solution(a, b, c);
}
