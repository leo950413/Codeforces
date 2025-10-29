#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int>dp(n+1, 0), v(n+1);
    vector<vector<int>>cnt(n+1);
    vector<int>ptr(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> v[i];
        cnt[v[i]].push_back(i);
    }
    for(int i=1; i<=n; i++){
        if(!(cnt[v[i]].size() - ptr[v[i]] < v[i])){
                 // in the range
            int idx = cnt[v[i]][ptr[v[i]] + v[i] - 1];
            ptr[v[i]]++;
            dp[idx] = max(dp[idx] , dp[i-1] + v[i]);
            // cout <<i<< " "<< idx  <<  " " <<dp[idx] <<" "<< ptr[v[i]] << "\n";
        }
        dp[i] = max(dp[i-1] , dp[i]);
        // cout << i << " " << dp[i] << "\n";
    }
    cout << dp[n] << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}