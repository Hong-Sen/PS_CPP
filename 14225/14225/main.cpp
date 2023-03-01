#include <iostream>
#include <set>
using namespace std;

int N;
int S[21];
set<int> sums;

void subsequence(int sum, int cnt, int idx) {
    if(cnt == N) return;
    for(int i=idx; i<N; i++) {
        sums.insert(sum + S[i]);
        subsequence(sum + S[i], cnt + 1, i+1);
    }
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>S[i];
    }
    
    subsequence(0,0,0);
    
    int n = 1;
    for(auto it: sums) {
        if(n != it) {
            cout<<n;
            return 0;
        }
        n++;
    }
    cout<<n;
  
    
}
