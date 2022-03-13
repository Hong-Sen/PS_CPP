#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int maxDif;
vector<int> answer(11,0);

bool pickMoreLessScore(vector<int> lion) {
    for(int i=10; i>=0; i--) {
        if(lion[i] == answer[i]) continue;
        if(lion[i] > answer[i]) return true;
        else return false;
    }
    return false;
}

void caculateScore(vector<int> apeach, vector<int> lion) {
    int apeachScore = 0, lionScore = 0;
    for(int i=0; i<apeach.size(); i++){
        if(lion[i] > apeach[i]) lionScore += 10 - i;
        else if(apeach[i] != 0) apeachScore += 10 - i;
    }
    int dif = lionScore - apeachScore;
    if(dif > 0){
        if(maxDif <= dif) {
            if(maxDif == dif && !pickMoreLessScore(lion)) return;
            maxDif = dif;
            answer = lion;
        }
    }
}

void doArchery(int idx, int arrow, vector<int> apeach, vector<int> lion) {
    if(arrow == 0) {
        caculateScore(apeach, lion);
        return;
    }
    if(idx == 11) {
        lion[10] = arrow;
        caculateScore(apeach, lion);
        return;
    }
    
    // 라이언이 점수 얻기(어피치 점수+1)
    if(arrow >= apeach[idx] + 1){
        lion[idx] = apeach[idx] + 1;
        doArchery(idx+1, arrow-apeach[idx]-1, apeach, lion);
        lion[idx] = 0;
    }
    
    // 어피치가 점수 얻기
    doArchery(idx+1, arrow, apeach, lion);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> lion(11,0);
    doArchery(0, n, info, lion);
    
    vector<int> v(1,-1);
    if(maxDif == 0) return v;
    return answer;
}

int main(){
    solution(1, {1,0,0,0,0,0,0,0,0,0,0});
}
