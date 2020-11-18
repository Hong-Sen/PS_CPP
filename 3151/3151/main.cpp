#include <iostream>
#include <algorithm>
using namespace std;

int grade[10001];

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>grade[i];
    }
    sort(grade,grade+n);
    long long cnt = 0; //정답개수가 10000*999*998
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            int sum = grade[i]+grade[j];
            //upper_bound - lower_bound = sum이 0인 경우
            int lower = lower_bound(grade+j+1, grade+n, -sum) - grade;
            int upper = upper_bound(grade+j+1, grade+n, -sum) - grade;
            cnt += upper-lower;
        }
    }
    cout<<cnt<<"\n";
}
