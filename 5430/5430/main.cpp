#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int T;
    string result;
    cin>>T;
    deque<int> v;
    for(int i=0;i<T;i++){
        cin.ignore();
        string p;
        cin>>p;
        int n;
        cin>>n;
        v.clear();
        
        //입력받기 ex)[1,2,3,4]
        string s;
        cin>>s;
        vector<char> num;
        for(int j=1; j<s.length()-1; j++){
            if(j==s.length()-2){
                num.push_back(s.at(j));
                string realnum;
                for(int k=0; k<num.size(); k++){
                    realnum += num[k];
                }
                v.push_back(stoi(realnum));
            }
            if(s.at(j) != ','){
                num.push_back(s.at(j));
            }
            else if(s.at(j) == ',' ){
                string realnum;
                for(int k=0; k<num.size(); k++){
                    realnum += num[k];
                }
                v.push_back(stoi(realnum));
                num.clear();
            }
            
        }
        
        //flag = error발생시 false
        bool flag = true;
        //p명령 수행하기
        bool reverse = false;
        int front = 0;
        int back = 0;
        int k=0;
        while(k != p.length()){
            if(p.at(k) == 'R'){
                if(!reverse)    reverse = true;
                else    reverse = false;
            }
            else if(p.at(k) == 'D'){
                if(!reverse)    front++;
                else    back++;
                if(front > v.size() || back > v.size()){
                    flag = false;
                    cout<<"error\n";
                    break;
                }
            }
            k++;
        }
        //error가 아니면
        if(flag){
            while(front != 0){
                v.pop_front();
                front--;
            }
            while(back != 0){
                v.pop_back();
                back--;
            }
//                        for(int l=0; l<v.size();l++){
//                            cout<<v[l]<<" ";
//                        }
            if(!reverse){
                string ans = "[";
                for(int l=0 ;l<v.size() ;l++){
                    ans += to_string(v[l]);
                    if(l != v.size()-1)     ans += ",";
                }
                ans += "]";
                cout<<ans<<"\n";
            }
            else{
                string ans = "[";
                for(int l=v.size()-1 ;l>=0 ;l--){
                    ans += to_string(v[l]);
                    if(l != 0)     ans += ",";
                }
                ans += "]";
                cout<<ans<<"\n";
            }
        }
    }
}
