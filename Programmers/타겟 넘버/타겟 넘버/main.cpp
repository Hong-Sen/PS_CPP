#include <iostream>
#include <string>
#include <vector>
using namespace std;

int result;

void dfs(vector<int> numbers, int target, int start, int sum){
    int sizeN = numbers.size();
    if(start == sizeN ){
        if(sum == target){
            result++;
        }
        return;
    }
    dfs(numbers, target, start+1, sum+numbers[start]);
    dfs(numbers, target, start+1, sum-numbers[start]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return result;
}

int main(){
    vector<int> numbers;
    int target = 3;
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    cout<< solution(numbers, target);
}
