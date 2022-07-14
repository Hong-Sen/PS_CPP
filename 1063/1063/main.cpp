//
//  main.cpp
//  1063
//
//  Created by 홍세은 on 2022/07/15.
//

#include <iostream>
using namespace std;

string king, stone, order;
int N;
int kingX, kingY, stoneX, stoneY;

bool isInside(int x, int y) {
    return x >= 0 && x <= 7 && y >= 1 && y <= 8;
}

int main(){
    cin>>king>>stone>>N;
    kingX = int(king[0] - 'A');
    kingY = int(king[1] - '0');
    stoneX = int(stone[0] - 'A');
    stoneY = int(stone[1] - '0');
    
    while (N--) {
        cin>>order;
        int x = 0, y = 0;
        if(order == "R") {
            x = 1;
        }
        else if(order == "L") {
            x = -1;
        }
        else if(order == "B") {
            y = -1;
        }
        else if(order == "T") {
            y = 1;
        }
        else if(order == "RT") {
            x = 1;
            y = 1;
        }
        else if(order == "LT") {
            x = -1;
            y = 1;
        }
        else if(order == "RB") {
            x = 1;
            y = -1;
        }
        else if(order == "LB") {
            x = -1;
            y = -1;
        }
        
        if(kingX + x == stoneX && kingY + y == stoneY) {
            if(isInside(stoneX + x, stoneY + y)) {
                kingX += x;
                kingY += y;
                stoneX += x;
                stoneY += y;
            }
        }
        else {
            if(isInside(kingX + x, kingY + y)) {
                kingX += x;
                kingY += y;
            }
        }
    }
    cout<<char(kingX + 'A')<<kingY<<"\n";
    cout<<char(stoneX + 'A')<<stoneY<<"\n";
    
}
