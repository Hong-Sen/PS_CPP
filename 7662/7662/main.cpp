#include <iostream>
#include <set>
using namespace std;

int T,k;
char c;
int n;

int main(){
    cin>>T;
    for(int l=0; l<T; l++){
        cin>>k;
        multiset<int> ms;
        for(int i=0; i<k; i++){
            cin>>c>>n;
            if(c == 'I'){
                ms.insert(n);
            }
            else{
                if(ms.empty()) continue;
                if(n == 1){
                    auto it = ms.end();
                    it--;
                    ms.erase(it);
                }
                else{
                    ms.erase(ms.begin());
                }
            }
        }
        if(ms.empty()) cout<<"EMPTY\n";
        else{
            auto endIt = ms.end();
            endIt--;
            cout<<*endIt<<" "<<*ms.begin()<<"\n";
        }
    }
}
