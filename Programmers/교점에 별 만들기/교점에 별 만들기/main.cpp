// Min, Max값 주의해서 설정하기
// intOverflow 항상 생각하기(특히 *부분)!
#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

set<pair<long long,long long>> points;
long long minX = 10000000002, minY = 10000000002, maxX = -10000000002, maxY = -10000000002;

void makePoint(vector<int> a, vector<int> b) {
    long long AD_BC = (long long)(a[0]*b[1]) - (long long)(a[1]*b[0]);
    if(AD_BC == 0) return;
    double x = (double((long long)a[1]*b[2]) - double((long long)a[2]*b[1])) / AD_BC;
    double y = (double((long long)a[2]*b[0])- double((long long)a[0]*b[2])) / AD_BC;
    if((x - (long long)x == 0) && (y - (long long)y == 0)) {
        points.insert({(long long)x, (long long)y});
        minX = min((long long)x, minX);
        minY = min((long long)y, minY);
        maxX = max((long long)x, maxX);
        maxY = max((long long)y, maxY);
    }
}
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    for(int i=0; i<line.size(); i++) {
        for(int j=i+1; j<line.size(); j++) {
            makePoint(line[i], line[j]);
        }
    }
    
    string str = "";
    for(int i=0; i<=maxX-minX; i++) {
        str += '.';
    }
    
    for(int i=0; i<=maxY-minY; i++) {
        answer.push_back(str);
    }
    
    for(auto it: points) {
        long long x = it.first - minX;
        long long y = it.second - minY;
        answer[abs(y-(maxY-minY))][x] = '*';
    }
    
    return answer;
}
