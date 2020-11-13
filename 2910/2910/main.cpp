#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct sequence{
    int num;
    int fre;
    int order;
};

bool cmp(sequence a, sequence b){
    if(a.fre == b.fre)  return a.order < b.order;
    else    return a.fre > b.fre;
}



sequence sq[1001]; //수열(숫자,빈도,순서)

int main(){
    int n,c;
    cin>>n>>c;
    map<int, int> m; //m[숫자] = 빈도수
    vector<int> order; //수열 순서
    
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(m[x] >= 1)    m[x]++;
        else    m[x] = 1;
        order.push_back(x);
    }
    
    int j=0;
    for(map<int, int>::iterator i=m.begin(); i!=m.end(); i++){
        sq[j].num = (*i).first;
        sq[j].fre = (*i).second;
        for(int l=0; l<order.size(); l++){
            if(order[l] == (*i).first){
                sq[j].order = l;
                break;
            }
        }
        j++;
    }
    
    sort(sq,sq+m.size(),cmp);
    
    for(int i=0; i<m.size(); i++){
        for(int k=0; k<sq[i].fre; k++){
            cout<<sq[i].num<<" ";
        }
    }
    
    
    
    
}
