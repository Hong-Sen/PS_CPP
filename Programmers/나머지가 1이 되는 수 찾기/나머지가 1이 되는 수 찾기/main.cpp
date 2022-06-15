#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    n -= 1;
    for(int i=2; i<=n; i++){
        if(n % i == 0) return i;
    }
    return 0;
}
