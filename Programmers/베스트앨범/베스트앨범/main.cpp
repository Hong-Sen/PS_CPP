#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first)  return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    vector<pair<int, int>> sameGenres[10001];
    
    for(int i=0; i<genres.size(); i++){
        if(m.find(genres[i]) != m.end()){
            m[genres[i]] += plays[i];
        }
        else{
            m.insert({genres[i], plays[i]});
        }
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

//    cout<<"장르별 합계"<<"\n";
//    for(int i=0; i<v.size(); i++){
//        cout<<v[i].first<<" "<<v[i].second<<"\n";
//    }
    
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<genres.size(); j++){
            if(v[i].first == genres[j]){
                sameGenres[i].push_back({plays[j], j});
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        sort(sameGenres[i].begin(), sameGenres[i].end(), cmp2);
    }
    
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<sameGenres[i].size(); j++){
            if(j > 1) break;
            answer.push_back(sameGenres[i][j].second);
            cout<<sameGenres[i][j].second<<"\n";
        }
    }
    
    return answer;
}

int main(){
    solution({"classic", "pop", "classic", "classic", "pop", "k-pop", "jazz"},{500, 600, 500, 800, 2500, 50000, 40000});
}
