#include<iostream>
#include<iostream>
using namespace std; 

void solve(){
    string s;
    cin >> s;
    int mx = 10;
    for(int i=0; i<s.length(); i++){
        mx = min(mx , s[i] - '0');
    }
    cout << mx<<"\n";
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}