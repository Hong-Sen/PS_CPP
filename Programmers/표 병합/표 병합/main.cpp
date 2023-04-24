#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string value[2502];
int cell[2502];

vector<string> splitCommand(string str) {
    vector<string> v;
    string result = "";
    str += ' ';
    for(char c: str) {
        if(c == ' '){
            v.push_back(result);
            result = "";
        }
        else {
            result += c;
        }
    }
    return v;
}

int getPos(int r, int c) {
    return (r-1) * 50 + c;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for(int i=1; i<=2500; i++) {
        cell[i] = i;
        value[i] = "EMPTY";
    }
    
    for(string command: commands) {
        vector<string> v = splitCommand(command);
        if(v[0] == "UPDATE" && v.size() == 4) {
            int r = stoi(v[1]), c = stoi(v[2]);
            int parent = cell[getPos(r,c)];
            value[parent] = v[3];
        }
        else if(v[0] == "UPDATE" && v.size() == 3) {
            for(int i=1; i<=2500; i++) {
                if(value[i] == v[1]) value[i] = v[2];
            }
        }
        else if(v[0] == "MERGE") {
            int r1 = stoi(v[1]), c1 = stoi(v[2]), r2 = stoi(v[3]), c2 = stoi(v[4]);
            int parent1 = cell[getPos(r1,c1)], parent2 = cell[getPos(r2,c2)];
            if(parent1 == parent2) continue;
            if(value[parent1] == "EMPTY" && value[parent2] != "EMPTY") {
                value[parent1] = value[parent2];
            }
            else {
                value[parent2] = value[parent1];
            }
            
            for(int i=1; i<=2500; i++) {
                if(cell[i] == parent2) cell[i] = parent1;
            }
        }
        else if(v[0] == "UNMERGE") {
            int r = stoi(v[1]), c = stoi(v[2]);
            int parent = cell[getPos(r,c)];
            string str = value[parent];
            value[parent] = "EMPTY";
            for(int i=1; i<=2500; i++) {
                if(cell[i] == parent) {
                    cell[i] = i;
                    value[i] = "EMPTY";
                }
            }
            value[getPos(r,c)] = str;
        }
        else {
            int r = stoi(v[1]), c = stoi(v[2]);
            int parent = cell[getPos(r,c)];
            answer.push_back(value[parent]);
        }
    }
    return answer;
}
