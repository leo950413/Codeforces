#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;


int main(){
    string s;
    set<string>st;
    long long ans = 0;
    while(getline(cin , s)){
        if(s[0] == '+'){
            st.insert(s.substr(1));
        }
        else if(s[0] == '-'){
            st.erase(s.substr(1));
        }
        else{
            int i=0; 
            while(s[i] != ':')i++;
            i++;
            ans += s.substr(i).size() * st.size();
        }
    }
    cout <<ans << "\n";
}