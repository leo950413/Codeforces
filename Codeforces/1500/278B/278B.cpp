#include<iostream>
#include<map>
using namespace std;

void solve(){
}
int main(){
    int t;
    cin >> t;
    map<string ,int>m;
    for(int i=0; i<t; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++){
            m[s.substr(j, 1)]++;
            if(j + 1 < s.size())m[s.substr(j, 2)]++;
        }
    }
    for(int i=0; i<26; i++){
        string c(1 , i + 'a');
        if(!m[c]){
            cout << c << "\n";
            return 0;
        }
    }
    for(int j=0; j<26; j++){
        for(int i=0; i<26; i++){
            string c = string(1, j + 'a') + string(1, i + 'a');
            if(!m[c]){
                cout << c << "\n";
                return 0;
            }
        }
    }
}