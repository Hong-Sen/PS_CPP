#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

string solution(int n) {
    string answer = "";
    while(n > 0) {
        n--;
        int rest = n % 3;
        answer = "124"[rest] + answer;
        n /= 3;
    }
    return answer;
}
