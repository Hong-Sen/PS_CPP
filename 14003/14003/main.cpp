#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,cnt;
int arr[1000001];
int p[1000001];
vector<int> ans;
vector<int> print;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    
    ans.push_back(arr[1]);
    for (int i=2; i<=n; i++) {
        if (ans[cnt] < arr[i]) {
            ans.push_back(arr[i]);
            cnt++;
            p[i] = cnt;
        }
        else {
            int pos = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[pos] = arr[i];
            p[i] = pos;
        }
    }
    
    cout << cnt + 1 << "\n";
    
    for(int i=n; i>=1 && cnt >=0; i--){
        if (p[i] == cnt) {
            print.push_back(arr[i]);
            cnt--;
        }
    }
    for (int i = print.size() - 1; i >= 0; i--)
        cout << print[i] << " ";
}
