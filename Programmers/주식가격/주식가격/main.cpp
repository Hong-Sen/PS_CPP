#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            answer[i]++;
            if(prices[i] > prices[j])  break;
        }
    }
    return answer;
}

int main(){
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(3);
    solution(prices);
}
