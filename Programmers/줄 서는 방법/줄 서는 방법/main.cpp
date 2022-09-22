#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer, nums;
    long long f = 1;
    for(int i=1; i<=n; i++) {
        f = i * f;
    }
    
    for(int i=1; i<=n; i++) {
        nums.push_back(i);
    }
    
    if(k == 1) return nums;
    
    long long d = 0,r = k-1;
    
    while(n != 1) {
        f = f / n;
        d = r / f;
        r = r % f;
        answer.push_back(nums[d]);
        nums.erase(nums.begin() + d);
        n--;
    }
    answer.push_back(nums[0]);
    return answer;
}
