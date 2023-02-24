#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0) {
        int n = storey % 10;
        
        if(n >= 6) {
            answer += 10 - n;
            storey += 10 - n;
        }
        else if(n == 5 && (storey / 10) % 10 >= 5) {
            answer += 10 - n;
            storey += 10 - n;
        }
        else {
            answer += n;
        }
        storey /= 10;
    }
    return answer;
}
