#include <iostream>
#include <vector>
using namespace std;

long long gcd(long a, long b){
    if(b == 0)  return a;
    else    return gcd(b,a%b);
}

long long solution(int w,int h) {
    long long answer = 1;
    if(w < h)   swap(w,h);
    long w1 = w;
    long h1 = h;
    answer =(w1*h1) - (w1+h1-gcd(w1,h1));
    return answer;
}

int main(){
    cout<<solution(8, 12);
}
