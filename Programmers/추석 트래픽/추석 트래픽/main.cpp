#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> simpleTimeLines;
    for(int i=0; i<lines.size(); i++){
        double h = stoi(lines[i].substr(11,2)) * 3600 * 1000;
        double m = stoi(lines[i].substr(14,2)) * 60 * 1000;
        double s = stod(lines[i].substr(17,6)) * 1000;
        double w = stod(lines[i].substr(23,lines[i].size()-24)) * 1000 - 1;
        double time = h + m + s;
        simpleTimeLines.push_back({time-w, time});
    }
    
    for(int i=0; i<simpleTimeLines.size(); i++){
        int cnt = 0, cnt2 = 0;
        int min = simpleTimeLines[i].first;
        int min2 = simpleTimeLines[i].second-1;
        for(int j=i; j<simpleTimeLines.size(); j++){
            if(min<= simpleTimeLines[j].first && simpleTimeLines[j].first <= min+1000) cnt++;
            else if(min<= simpleTimeLines[j].second && simpleTimeLines[j].second < min+1000) cnt++;
            else if(simpleTimeLines[j].first < min && simpleTimeLines[j].second > min+1000) cnt++;
            
            if(min2<= simpleTimeLines[j].first && simpleTimeLines[j].first <= min2+1000) cnt2++;
            else if(min2<= simpleTimeLines[j].second && simpleTimeLines[j].second <= min2+1000) cnt2++;
            else if(simpleTimeLines[j].first <= min2 && simpleTimeLines[j].second >= min2+1000) cnt2++;
        }
        cnt = max(cnt, cnt2);
        answer = max(answer,cnt);
    }
    return answer;
}

int main(){
    cout<<solution({"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"}); // 1
    
    cout<<"\n\n";
    
    cout<<solution({ "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"}); // 2
   
}

