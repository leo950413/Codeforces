#include<string>
#include<vector>
#include<iostream>

using namespace std;

int main(){
    string s;
    int n;
    cin >> s;
    cin >> n;
    s.insert(s.begin(), '0');
    vector<int>dp(s.length() + 1 , 0);
    char prev = s[0];
    for(int i=1; i<s.length(); i++){
        dp[i] = dp[i-1] + (prev == s[i]);
        prev = s[i];
    }
    for(int i=0; i<n; i++){
        int l,r;
        cin >> l >> r;
        cout << dp[r] - dp[l] << "\n";
    }
}