#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

deque<char> sn[9];
int k;
bool visited[5];

char findSN(deque<char> dq, int n){
    char tmp[3];
    switch (n) {
        case 2:
            for(int i=0; i<=n; i++){
                tmp[i] = dq.front();
                dq.pop_front();
            }
            for(int i=n; i>=0; i--){
                dq.push_front(tmp[i]);
            }
            return tmp[2];
            break;
            
        case 6:
            for(int i=0; i<2; i++){
                tmp[i] = dq.back();
                dq.pop_back();
            }
            for(int i=1; i>=0; i--){
                dq.push_back(tmp[i]);
            }
            return tmp[1];
            break;
            
        default:
            return -1;
            break;
    }
}

void rotation(int n, int d){
    switch (n) {
        case 1:
            visited[1] = true;
            if(findSN(sn[1], 2) != findSN(sn[2], 6) && !visited[2]){
                rotation(2, d*(-1));
            }
            break;
            
        case 2:
            visited[2] = true;
            if(findSN(sn[2], 6) != findSN(sn[1], 2) && !visited[1]){
                rotation(1, d*(-1));
            }
            if(findSN(sn[2], 2) != findSN(sn[3], 6) && !visited[3]){
                rotation(3, d*(-1));
            }
            break;
            
        case 3:
            visited[3] = true;
            if(findSN(sn[3], 6) != findSN(sn[2], 2) && !visited[2]){
                rotation(2, d*(-1));
            }
            if(findSN(sn[3], 2) != findSN(sn[4], 6) && !visited[4]){
                rotation(4, d*(-1));
            }
            break;
            
        case 4:
            visited[4] = true;
            if(findSN(sn[4], 6) != findSN(sn[3], 2) && !visited[3]){
                rotation(3, d*(-1));
            }
            break;
            
        default:
            break;
    }
    //n번 바퀴 회전시키기
    if(d == 1){
        sn[n].push_front(sn[n].back());
        sn[n].pop_back();
    }
    else if(d == -1){
        sn[n].push_back(sn[n].front());
        sn[n].pop_front();
    }
}

int result(){
    int sum = 0;
    if(sn[1].front() == '1') sum += 1;
    if(sn[2].front() == '1') sum += 2;
    if(sn[3].front() == '1') sum += 4;
    if(sn[4].front() == '1') sum += 8;
    return sum;
}

int main(){
    for(int i=1; i<=4; i++){
        string s;
        cin>>s;
        for(int j=0; j<8; j++){
            sn[i].push_back(s.at(j));
        }
    }
    cin>>k;
    int num,direction;
    for(int i=0; i<k; i++){
        cin>>num>>direction;
        memset(visited, false, sizeof(visited));
        rotation(num, direction);
    }
    
    cout<<result();
}
