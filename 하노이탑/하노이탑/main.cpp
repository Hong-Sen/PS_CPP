// 3번 기둥에 쌓여진 디스크에 변화가 있을 때 제일 위에 놓여진 디스크 번호 출력 프로그램

#include <iostream>
#include <stack>
using namespace std;

int tc;
stack<int> st[4];

void hanoi(int n, int start, int to, int by)
{
    if(n==1) {
        int prev = st[3].size();
        st[to].push(st[start].top());
        st[start].pop();
        if(st[3].size()!=prev) {
            if(st[3].empty()) cout<<"0 ";
            else cout<<st[3].top()<<" ";
        }
    }
    else
    {
        hanoi(n-1, start, by, to);
        int prev = st[3].size();
        st[to].push(st[start].top());
                st[start].pop();
        if(st[3].size()!=prev) {
            if(st[3].empty()) cout<<"0 ";
            else cout<<st[3].top()<<" ";
        }
        hanoi(n-1,by,to,start);
    }
}
int main() {
    cin>>tc;
    for(int i=0;i<tc;i++) {
        int n;
        cin>>n;
        for(int i=n;i>=1;i--) {
            st[1].push(i);
        }
        hanoi(n,1,3,2);
        cout<<endl;
        for(int i=1;i<=3;i++) {
            while (!st[i].empty()) {
                st[i].pop();
            }
        }
    }
}
