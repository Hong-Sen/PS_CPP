#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<pair<string, int>> v;
    v.push_back(make_pair("black", 1));
    v.push_back(make_pair("brown", 10));
    v.push_back(make_pair("red", 100));
    v.push_back(make_pair("orange", 1000));
    v.push_back(make_pair("yellow", 10000));
    v.push_back(make_pair("green", 100000));
    v.push_back(make_pair("blue", 1000000));
    v.push_back(make_pair("violet", 10000000));
    v.push_back(make_pair("grey", 100000000));
    v.push_back(make_pair("white", 1000000000));
    
    string color;
    long result=0;
    
    for(int i=0;i<3;i++){
        cin>>color;
        for(int j=0;j<10;j++){
            if(v[j].first == color){
                if(i==0) result += 10*j;
                else if(i==1) result+= j;
                else result *= v[j].second;
            }
        }
    }
    

    cout<<result<<"\n";
}
