#include <iostream>
#include <string>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    int ccnt = 51;
    int dif = b.size() - a.size();
    
    if(dif == 0){
        int cnt = 0;
        for(int i=0; i<a.size(); i++){
            if(a.at(i) != b.at(i))  cnt++;
        }
        cout<<cnt<<"\n";
    }
    else{
        for(int j=0; j<=dif; j++){
            int cnt=0;
            for(int i=0; i<a.size(); i++){
                if(a.at(i) != b.at(i+j)) cnt++;
                    }
            if(ccnt > cnt)  ccnt = cnt;
            
        }
        cout<<ccnt<<"\n";
    }
}
