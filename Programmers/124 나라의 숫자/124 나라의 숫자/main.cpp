#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

string solution(int n) {
    string answer = "";
    char nums[3] = {'1','2','4'};
    int len = 0;
    while(n > 0) {
        len++;
        n -= pow(3,len);
    }
    
    n += pow(3,len) - 1;
    
    while(1) {
        len--;
        if(len == 0) {
            answer += nums[n];
            break;
        }
        int dn = n/pow(3,len);
        n = n % int(pow(3,len));
        answer += nums[dn];
    }
    return answer;
}
