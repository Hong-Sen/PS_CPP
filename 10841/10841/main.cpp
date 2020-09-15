#include <iostream>
#include <queue>
using namespace std;

struct student{
    int age;
    string name;
    int index;
    student(int a, string n, int i){
        age = a;
        name = n;
        index = i;
    }
};

struct cmp
{
    bool operator() (student s1, student s2){
        if(s1.age != s2.age){
            return s1.age > s2.age;
        }
        else{
            return s1.index > s2.index;
        }
    }
};

int main(){
    int n;
    cin>>n;
    priority_queue<student, vector<student>, cmp > pq;
    
    for(int i=0;i<n;i++){
        int age;
        string name;
        int index = i;
        cin>>age>>name;
        pq.push(student(age,name,index));
    }
    
    while(!pq.empty()){
        cout<<pq.top().age<<" "<<pq.top().name<<"\n";
        pq.pop();
    }
    
    
}
