#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int cnt = 0;
    int numberSize = number.size();
    int i = 0;
    while(i<number.size()){
        if(cnt >= k) break;
        if(number[i] < number[i+1]){
            number.erase(i,1);
            cnt++;
            i=0;
        }
        else{
            i++;
        }
    }
    if(numberSize - k != number.size()){
        number.erase(number.size() - k, k);
    }
    answer = number;
    return answer;
}
