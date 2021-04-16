#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct race{
    int date;
    int start;
    int finish;
};

bool cmp(race r1, race r2){
    if(r1.date == r2.date){
        return r1.finish < r2.finish;
    }
    else    return r1.date < r2.date;
}

int scenario(vector<race> v){
    int cnt = 0;
    int curDate = 0, curStart = 0, curFinish = 0;
    int i = 0;
    while (i < v.size()) {
        //다음날
        if(v[i].date > curDate){
            curDate = v[i].date;
            curStart = v[i].start;
            curFinish = v[i].finish;
            cnt++;
        }
        //같은날
        else{
            if( v[i].start >= curFinish){
                curStart = v[i].start;
                curFinish = v[i].finish;
                cnt++;
            }
        }
        i++;
    }
    return cnt;
}

int main(){
    int n,m,d,s,e;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>m;
        vector<race> v;
        for(int j=0; j<m; j++){
            cin>>d>>s>>e;
            v.push_back({d,s,e});
        }
        sort(v.begin(), v.end(), cmp);
        cout<<"Scenario #"<<i<<":"<<"\n";
        cout<<scenario(v)<<"\n\n";
    }
}
