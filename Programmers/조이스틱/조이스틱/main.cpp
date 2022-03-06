#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name) {
    int cnt = 0, move = 0;
    for(int i=0; i<name.size(); i++){
        cnt += min(name[i] - 'A', 'Z' - name[i]);
        if(name[i] != 'A') {
            int next = i+1;
            while(next < name.size() && name[next] == 'A') {
                next++;
            }
            int tmp = 2*i + name.size() - next;
            move = min(name.size()-1, tmp);
        }
    }

    return cnt + move;
}
