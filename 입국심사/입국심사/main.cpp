#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    long long start = 0;
    long long end = times[times.size()-1]*n;
    
    while(start < end) {
        long long mid = (start+end) / 2;
        long long sum = 0;
        long long minRest = 1000001000;
        long long minTime = 0;
        long long sameTime = 0;
        
        if(mid == 0){
            answer = 1;
            break;
        }
        
        for(int i:times) {
            sum += mid/i;
            if(minRest > mid%i){
                minTime = i;
                minRest = mid%i;
            }
            if(mid%i == 0){
                sameTime++;
            }
        }
        if(sum > n){
            if(sum - sameTime + 1 <= n)  sum = n;
            end = mid;
        }
        else if(sum < n){
            start = mid;
        }
        if(sum == n){
            answer = mid - minRest;
            break;
        }
    }
    return answer;
}
