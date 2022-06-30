#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct FileType {
    string head;
    int number;
    string tail;
    string fileName;
};

vector<FileType> v;

void swap(int a, int b) {
    FileType tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}

string toUpper(string s) {
    string result = "";
    for(char c : s) {
        if(c >= 'a') result += char(c - 'a' + 'A');
        else result += c;
    }
    return result;
}

void sort() {
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v.size()-i-1; j++) {
            if(v[j].head > v[j+1].head) {
                swap(j, j+1);
            }
            else if(v[j].head == v[j+1].head) {
                if(v[j].number > v[j+1].number) {
                    swap(j, j+1);
                }
            }
        }
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    for(string file: files) {
        int type = 0;
        string s = "";
        FileType ft;
        ft.fileName = file;
        file += " ";
        for(int i=0; i<file.size(); i++) {
            if(type == 0 && file[i] >= '0' && file[i] <= '9') {
                ft.head = toUpper(s);
                s = "";
                type++;
            }
            if(type == 1 && (file[i] <'0' || file[i] > '9')) {
                ft.number = stoi(s);
                ft.tail = file.substr(i);
                break;
            }
            s += file[i];
        }
        v.push_back(ft);
    }
    
    sort();
    
    for(int i=0; i<v.size(); i++) {
        answer.push_back(v[i].fileName);
    }
    
    return answer;
}
