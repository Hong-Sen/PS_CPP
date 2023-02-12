#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Score {
  int score1, score2, idx;
    Score(int s1, int s2, int i) {
        score1 = s1;
        score2 = s2;
        idx = i;
    }
};

bool cmp(Score a, Score b) {
    // if(a.score1 == b.score1) return a.score2 <= b.score2;
    return a.score1 < b.score1;
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    vector<Score> idxScores;
    vector<pair<int,int>> sum;
    
    for(int i=0; i<scores.size(); i++) {
        idxScores.push_back(Score(scores[i][0], scores[i][1], i));
    }
    
    sort(idxScores.begin(), idxScores.end(), cmp);
    
    for(int i=0; i<idxScores.size(); i++) {
        for(int j=i+1; j<idxScores.size(); j++) {
            if(idxScores[i].score1 < idxScores[j].score1 && idxScores[i].score2 < idxScores[j].score2)  {
                if(idxScores[i].idx == 0) return -1;
                idxScores[i].score1 = -1;
                idxScores[i].score2 = -1;
            }
        }
    }
    
    for(int i=0; i<idxScores.size(); i++) {
        sum.push_back({idxScores[i].score1 + idxScores[i].score2, idxScores[i].idx});
    }
    
    sort(sum.begin(), sum.end(), greater<>());
    
    int sameScore = 1;
    for(int i=0; i<sum.size(); i++) {
        if(i == 0) answer = 1;
        else {
            if(sum[i].first == sum[i-1].first) sameScore++;
            else {
                answer += sameScore;
                sameScore = 1;
            }
        }
        if(sum[i].second == 0 || sum[i].first < 0)  break;
    }
    return answer;
}
