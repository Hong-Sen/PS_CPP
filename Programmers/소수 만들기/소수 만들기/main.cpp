#include <vector>
#include <iostream>
using namespace std;

 vector<int> numList;
bool isNotPrimeNumber[3001];
int answer;

void getSubset(int idx, int cnt, int sum){
    if(cnt == 3) {
        if(!isNotPrimeNumber[sum]) answer++;
        return;
    }
    for(int i=idx; i<numList.size(); i++){
        getSubset(i+1, cnt+1, sum+numList[i]);
    }
}

int solution(vector<int> nums) {
    answer = 0;
    numList = nums;
    
    for(int i=2; i<3001; i++){
        if(isNotPrimeNumber[i]) continue;
        for(int j=i+i; j<3001; j+=i) {
            isNotPrimeNumber[j] = true;
        }
    }
    
    getSubset(0,0,0);
    
    return answer;
}
