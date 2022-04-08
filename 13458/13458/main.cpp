#include <iostream>
#include <vector>
using namespace std;

int N, x, B, C;
vector<int> people;
long long result;

int caculate(int x){
    int cnt = 1;
    if(x <= B) return 1;
    cnt += (x - B) / C ;
    if((x - B) % C != 0) cnt += 1;
    return cnt;
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>x;
        people.push_back(x);
    }
    cin>>B>>C;
    for(int i=0; i<N; i++){
        result += caculate(people[i]);
    }
    cout<<result;
}
