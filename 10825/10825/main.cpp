#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct student{
    string name;
    int kor;
    int eng;
    int math;
}Student;

student s[100001];

bool cmp(student s1, student s2){
    if(s1.kor != s2.kor)    return s1.kor > s2.kor;
    else if(s1.eng != s2.eng) return s1.eng < s2.eng;
    else if(s1.math != s2.math) return s1.math > s2.math;
    else    return s1.name < s2.name;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n ;i++){
        cin>>s[i].name>>s[i].kor>>s[i].eng>>s[i].math;
    }
    
    sort(s, s+n, cmp);
    for(int i=0; i<n; i++){
        cout<<s[i].name<<"\n";
    }
}
