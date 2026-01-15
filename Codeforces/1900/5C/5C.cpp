#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>freq;
vector<int>ex;
vector<int>s2;

int main(){
    freq.resize(1e6, 0);
    ex.resize(1e6 ,0);
    s2.resize(1e6 , 0);
    int mx = 0;
    string s;
    stack<int>st;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if(c == '('){
            st.push(i);
        }
        else{
            if(st.empty()){
                ex[i] = -1;
                s2[i] = -1;
            }
            else{
                int idx = st.top();
                st.pop();
                s2[i] = idx;
                ex[i] = idx;
                if(idx > 0 && s[idx-1] == ')' && s2[idx-1] >= 0){
                    ex[i] = ex[idx-1];
                }
                int len = i - ex[i] + 1;
                freq[len]++;
                mx = max(len , mx);
            }
        }
    }
    freq[0] = 1;
    cout  << mx << " " << freq[mx];
}