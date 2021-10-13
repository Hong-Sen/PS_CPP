#include <iostream>
#include <vector>
using namespace std;

int N,M;
int truth,truthNum;
int partyPeople,num;
vector<int> know;
vector<int> party[51];
int parent[51];
int cnt;

int findParent(int a){
    if(a == parent[a]) return a;
    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

int main(){
    cin>>N>>M;
    cin>>truth;
    for(int i=0; i<truth; i++){
        cin>>truthNum;
        know.push_back(truthNum);
    }
    for(int i=0; i<M; i++){
        cin>>partyPeople;
        for(int j=0; j<partyPeople; j++){
            cin>>num;
            party[i].push_back(num);
        }
    }
    if(truth == 0){
        cout<<M;
        return 0;
    }
    // x의 부모 = x
    for(int i=1; i<=N; i++)
        parent[i] = i;
    
    // 파티 같이 하는 사람들 부모 하나로 합치기
    for(int i=0; i<M; i++){
        int p = party[i][0];
        for(int j=1; j<party[i].size(); j++){
            unionParent(p, party[i][j]);
        }
    }
    
    // 진실을 아는 사람들의 부모와 비교하기
    for(int i=0; i<M; i++){
        bool flag = true;
        for(int j=0; j<party[i].size(); j++){
            if(!flag) break;
            int p1 = party[i][j];
            for(int k=0; k<truth; k++){
                int p2 = know[k];
                if(findParent(p1) == findParent(p2)){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cnt++;
    }
    cout<<cnt;
}
