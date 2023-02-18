#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<int> room;

    sort(book_time.begin(), book_time.end());
    
    for(int i=0; i<book_time.size(); i++) {
        int start = 0, finish = 0;
        for(int j=0; j<2; j++) {
            int h = stoi(book_time[i][j].substr(0,2));
            int m = stoi(book_time[i][j].substr(3,2));
            if(j==0) start = h * 60 + m;
            else finish = h * 60 + m + 10;
        }
        bool flag = false;
        for(int k=0; k<room.size(); k++) {
            if(room[k] <= start) {
                room[k] = finish;
                flag = true;
                break;
            }
        }
        if(!flag) room.push_back(finish);
        sort(room.begin(), room.end());
    }
    
    
    return room.size();
}
