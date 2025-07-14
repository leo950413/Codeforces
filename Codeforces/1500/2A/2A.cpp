#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main(){
    int rect[1001];
    string recs[1001];
    int N;
    cin >> N;
    map<string , int>m;
    vector<string> candidate;
    int idx = 0;
    while(N--){
        cin >> recs[idx]>> rect[idx];
        if(!m.count(recs[idx])){
            m[recs[idx]] = 0;
        }
        m[recs[idx]] += rect[idx];
        idx++;
    }
    int max = -1;
    for(auto s : m){
        if(s.second > max){
            max = s.second;
        }
    }
    for(auto s : m){
        if(s.second == max){
            candidate.push_back(s.first);
        }
    }
    if(candidate.size() == 1){
        cout << candidate[0] <<"\n";
    }
    else{ 
        m.clear();
        for(int i=0; i<=idx; i++){
            if(!m.count(recs[i])){
                m[recs[i]] = 0;
            }
            m[recs[i]] += rect[i];
            if(m[recs[i]] >= max){
                for(auto s :candidate){
                    if(recs[i] == s){
                        cout << s << "\n";
                        return 0;
                    }
                }

            }
        }
    }
}