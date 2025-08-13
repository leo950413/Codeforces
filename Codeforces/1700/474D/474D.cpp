#include<iostream>
#include<vector>
using namespace std;
int main(){
    const int mx = 1e5+1;
    const int mod = 1e9 + 7;
    vector<long long>dp(mx , 1); // R , RR , RRR , ...
    int t,k;
    cin >> t >> k;
    for(int i=1; i<mx; i++){
        if(i-k>=0){
            dp[i] = dp[i-k] + dp[i-1];
            // | | + R 
            // | | + k*W
            // cout << dp[i] << "\n";
            dp[i] %= mod;
        }
    }
    vector<long long>pre(mx , 0);
    for(int i=1; i<mx; i++){
        pre[i] += pre[i-1] + dp[i];
    }
    for(int i=0; i<t; i++){
        int a,b;
        cin >> a >> b;
        cout << ((pre[b] - pre[a-1] + mod) % mod) << "\n";
    }
}