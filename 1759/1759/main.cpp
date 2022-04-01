//
//  main.cpp
//  1759
//
//  Created by 홍세은 on 2022/04/01.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int L,C;
char c;
string vowels; // 모음
vector<char> alphabets;
char answer[16];
map<string, int> mp;

bool check(char result[16]){
    int consonantsCnt = 0, vowelsCnt = 0;
    for(int i=0; i<L; i++){
        if(vowels.find(result[i]) >= 0 && vowels.find(result[i]) < L) vowelsCnt++;
        else consonantsCnt++;
    }
    if(vowelsCnt >= 1 && consonantsCnt >=2) return true;
    else return false;
}

void dfs(int idx, int resultIdx, char result[16]){
    if(resultIdx == L){        
        if(check(result)){
            string str = "";
            for(int i=0; i<L; i++){
                str += result[i];
            }
            mp.insert({str, 0});
        }
        return;
    }
    if(idx >= alphabets.size() || L-resultIdx > alphabets.size() - idx) return;
    
    for(int i=idx; i<alphabets.size(); i++){
        // alphabets[idx] 담기
        result[resultIdx] = alphabets[i];
        dfs(i+1, resultIdx+1, result);
        // alphabets[idx] 담지 않기
        result[resultIdx] = ' ';
        dfs(i+1, resultIdx, result);
    }
}

int main(){
    cin>>L>>C;
    for(int i=0; i<C; i++){
        cin>>c;
        alphabets.push_back(c);
        if(c == 'a' || c == 'e' || c == 'i' || c== 'o' || c == 'u') vowels += c;
    }
    
    sort(alphabets.begin(), alphabets.end());
    

    dfs(0, 0, answer);
    
    for(auto it: mp){
        cout<<it.first<<"\n";
    }
}
