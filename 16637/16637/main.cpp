#include <iostream>
#include <vector>
using namespace std;

int N;
string s;
vector<int> nums;
vector<char> opers;
int result;
bool flag;

int cacluate(int a, int b, char c) {
    switch (c) {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        default:
            return 0;
            break;
    }
}

void dfs(int idx, int n) {
    if(idx > nums.size()-1) {
        if(!flag) { // 최초의 result값 설정
            result = n;
            flag = true;
        }
        else result = max(result, n);
        return;
    }
    
    if(idx == 0) dfs(idx + 1, nums[0]);
    else if(idx == nums.size()-1) dfs(idx + 1, cacluate(n, nums[idx], opers[idx-1]));
    else {
        // 괄호 X
        dfs(idx + 1, cacluate(n, nums[idx], opers[idx-1]));
        // 괄호 적용
        dfs(idx + 2, cacluate(n, cacluate(nums[idx], nums[idx+1], opers[idx]), opers[idx-1]));
    }
}

int main() {
    cin>>N>>s;
    string tmp;
    for(int i=0; i<s.size(); i++) {
        if(i % 2 == 0) nums.push_back(int(s[i]) - '0');
        else opers.push_back(s[i]);
    }
    
    dfs(0, 0);
    
    cout<<result;
}
