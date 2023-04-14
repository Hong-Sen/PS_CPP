// 40:40
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int emoticonSize;
vector<vector<int>> salePercent;

void makeSale(vector<int> v) {
    if(v.size() == emoticonSize) {
        salePercent.push_back(v);
        return;
    }
    
    for(int i=10; i<=40; i+=10) {
        v.push_back(i);
        makeSale(v);
        v.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    emoticonSize = emoticons.size();
    vector<int> v;
    makeSale(v);
    
    for(int i=0; i<salePercent.size(); i++) {
        int emoticonPlus = 0, price = 0;
        vector<int> percents = salePercent[i];
        
        for(int j=0; j<users.size(); j++) {
            int pay = 0;
            for(int l=0; l<percents.size(); l++) {
                if(users[j][0] <= percents[l]) {
                    pay += double(emoticons[l]) * double(100 - percents[l]) / 100;
                }
            }
            
            if(pay >= users[j][1]) {
                emoticonPlus++;
            }
            else {
                price += pay;
            }
        }
        if(i == 0) {
            answer.push_back(emoticonPlus);
            answer.push_back(price);
        }
        else{
            if(answer[0] < emoticonPlus || (answer[0] == emoticonPlus && answer[1] < price)) {
                answer[0] = emoticonPlus;
                answer[1] = price;
            }
        }
    }
    return answer;
}
