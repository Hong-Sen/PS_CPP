#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cntZero = 0;
    int cntSame = 0;
    for(int i:lottos){
        for(int j:win_nums){
            if(i == j){
                cntSame++;
                break;
            }
            if(i == 0){
                cntZero++;
                break;
            }
        }
    }
    if(cntZero == 6)    cntZero = 5;
    
    switch(cntSame){
        case 6:
            answer.push_back(1);
            answer.push_back(1);
            break;
        case 5:
            answer.push_back(2-cntZero);
            answer.push_back(2);
            break;
        case 4:
            answer.push_back(3-cntZero);
            answer.push_back(3);
            break;
        case 3:
            
            answer.push_back(4-cntZero);
            answer.push_back(4);
            break;
        case 2:
            answer.push_back(5-cntZero);
            answer.push_back(5);
            break;
        default:
            answer.push_back(6-cntZero);
            answer.push_back(6);
            break;
    }
    
    return answer;
}

int main() {
    vector<int> lottos;
    vector<int> win_nums;
    
    lottos.push_back(44);
    lottos.push_back(1);
    lottos.push_back(0);
    lottos.push_back(0);
    lottos.push_back(31);
    lottos.push_back(25);
    win_nums.push_back(31);
    win_nums.push_back(10);
    win_nums.push_back(45);
    win_nums.push_back(1);
    win_nums.push_back(6);
    win_nums.push_back(19);
    solution(lottos, win_nums);
    
}
