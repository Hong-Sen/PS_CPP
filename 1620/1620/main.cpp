#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n,m;
int start;
int finish;
int mid;
vector<pair<string, int>> dogam;
vector<string> dogamName;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    
    
    
    for(int i=1;i<=n;i++){
        string name;
        cin>>name;
        dogam.push_back(make_pair(name,i));
        dogamName.push_back(name);
    }
    
    
    sort(dogam.begin(), dogam.end());
    
    for(int i=0;i<m;i++){
        string st;
        cin>>st;
        if((int)(st.at(0))<=57){
            cout<<dogamName[stoi(st)-1]<<"\n";
        }
        
        else{
            start= 0;
            finish = n-1;
            while(finish>=start){
                mid = (start+finish)/2;
                if(dogam[mid].first > st )
                    finish = mid-1;
                else if(dogam[mid].first < st)
                    start = mid+1;
                else{
                    cout<<dogam[mid].second<<"\n";
                    break;
                }
            }
        }
        
    }
}
