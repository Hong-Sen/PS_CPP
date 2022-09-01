//
//  main.cpp
//  휴대폰 번호 가리기
//
//  Created by 홍세은 on 2022/09/01.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    for(int i=0; i<phone_number.size() - 4; i++) {
        phone_number[i] = '*';
    }
    return phone_number;
}

int main(){
    cout<<solution("01033334444");
}
