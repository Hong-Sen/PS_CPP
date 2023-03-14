#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,L,R,X;
int level[16];
int result;

void pickProblem(int idx, vector<int> problems, int sum) {
    if(problems.size() >= 2) {
        if(sum > R) return;
        if(sum >= L && (problems[problems.size()-1] - problems[0] >= X)) {
            result++;
        }
    }
    
    if(idx >= N) return;
    
    for(int i=idx; i<N; i++) {
        problems.push_back(level[i]);
        pickProblem(i+1, problems, sum + level[i]);
        problems.pop_back();
    }
}

int main() {
    cin>>N>>L>>R>>X;
    for(int i=0; i<N; i++) {
        cin>>level[i];
    }
    
    sort(level,level+N);
    
    vector<int> v;
    pickProblem(0, v, 0);
    
    cout<<result;
}
