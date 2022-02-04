//
//  main.cpp
//  1049
//
//  Created by 홍세은 on 2022/02/04.
//

#include <iostream>
#include <vector>
using namespace std;

int N,M;
int package = 1001, one = 1001;
int p = 1001,o = 1001;
int result;

int main(){
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>p>>o;
        package = min(p, package);
        one = min(o, one);
    }
    cout<<package<<" "<<one<<"\n";
    
    if(N%6 == 0){
        result = package*(N/6);
    }
    else{
        result = package*(N/6+1);
    }
    result = min(result, min(one*N, (N/6)*package + (N%6)*one));
    cout<<result;
}
