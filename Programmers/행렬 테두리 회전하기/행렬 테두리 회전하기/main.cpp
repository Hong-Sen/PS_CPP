#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    //행렬 초기화
    int n = 1;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            arr[i][j] = n++;
        }
    }
    
    for(int i=0; i<queries.size(); i++){
        int y1 = queries[i][0]-1;
        int y2 = queries[i][2]-1;
        int x1 = queries[i][1]-1;
        int x2 = queries[i][3]-1;
        
        int tmp = arr[y1][x1];
        int minNum = tmp;
        int index = 0;
        for(int j=y1; j<y2; j++){
            arr[j][x1] = arr[j+1][x1];
            minNum = min(minNum, arr[j][x1]);
        }
        for(int j=x1; j<x2; j++){
            arr[y2][j] = arr[y2][j+1];
            minNum = min(minNum,  arr[y2][j]);
        }
        for(int j=y2; j>y1; j--){
            arr[j][x2] = arr[j-1][x2];
            minNum = min(minNum, arr[j][x2]);
        }
        for(int j=x2; j>x1+1; j--){
            arr[y1][j] = arr[y1][j-1];
            minNum = min(minNum, arr[y1][j]);
        }
        arr[y1][x1+1] = tmp;
        answer.push_back(minNum);
    }
    return answer;
}
int main(){
    vector<vector<int>> v;
    v.push_back({2,2,5,4});
    v.push_back({3,3,6,6});
    v.push_back({5,1,6,3});
    solution(6, 6, v);
}
