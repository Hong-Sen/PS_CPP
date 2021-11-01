#include <iostream>
#include <algorithm>
using namespace std;

int N,L;
double dis[1001];
int cnt;

int main(){
    cin>>N>>L;
    for(int i=0; i<N; i++){
        cin>>dis[i];
    }
    sort(dis,dis+N);
    int i = 0;
    while (i<N) {
        double first = dis[i];
        i++;
        while (dis[i] + 1 - first <= L && i<N) {
            i++;
        }
        cnt++;
    }
    cout<<cnt;
}
