#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
set<string> s;
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string x;
        cin>>x;
        sort(x.begin(), x.end());
        s.insert(x);
    }
    cout<<s.size();
}

//
//int alphabet[100][26];
//
//void reset(int k,int n){
//    for(int i=0; i<26; i++){
//        alphabet[k][i] = n;
//    }
//}
//
//int main(){
//    int n;
//    cin>>n;
//    int cnt = n;
//    for(int i=0; i<n; i++){
//        string s;
//        cin>>s;
//        for(int j=0; j<s.length(); j++){
//            alphabet[i][(int)s.at(j)-97]++;
//        }
//    }
//    bool flag = true;
//    int tmp = -1;
//    for(int i=0; i<n-1; i++){
//        for(int j=i+1; j<n; j++){
//            for(int k=0; k<26; k++){
//                if(alphabet[i][k] != alphabet[j][k]){
//                    //cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<"\n";
//                    flag = false;
//                    break;
//                }
//            }
//            if(flag){
//                cnt--;
//                reset(j,tmp--);
//            }
//            else{
//                flag = true;
//            }
//        }
//    }
//    cout<<cnt;
//}
//
