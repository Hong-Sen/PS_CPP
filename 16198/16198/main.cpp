//
//  main.cpp
//  16198
//
//  Created by 홍세은 on 2023/02/09.
//

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> weights;
int result;

void saveEnergy(vector<int> v, int sum) {
    if(v.size() == 2) {
        result = max(result, sum);
        return;
    }
    for(int i=1; i<v.size()-1; i++) {
        vector<int> tmp = v;
        int energy = v[i-1] * v[i+1];
        tmp.erase(tmp.begin() + i);
        saveEnergy(tmp, sum + energy);
    }
}

int main() {
    cin>>N;
    int w;
    for(int i=0; i<N; i++) {
        cin>>w;
        weights.push_back(w);
    }
    
    saveEnergy(weights, 0);
    
    cout<<result;
}
