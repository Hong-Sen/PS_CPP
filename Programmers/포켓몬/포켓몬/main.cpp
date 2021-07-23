#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int,int> m;
    int nSize = nums.size();
    for(int i:nums){
        m.insert({i,1});
    }
    if(m.size() > nSize/2)  answer = nSize/2;
    else    answer = m.size();
    return answer;
}

int main(){
    vector<int> n;
    n.push_back(3);
    n.push_back(3);
    n.push_back(3);
    n.push_back(2);
    n.push_back(2);
    n.push_back(4);
    cout<<solution(n);
}
