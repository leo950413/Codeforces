#include<iostream>
#include<vector>
const int MOD = 1e9 + 7;
using namespace std;

int main(){
    // consider {some prfix}2|0 -> 0 depends on 2
    // 0 | 0 for all possible would be  0->(1,2,3...m) the second 0 : (1, (1,2)) (2, (1,2,3)) .. 
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<vector<int>> dp(n, vector<int>(m+1 ,0));
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(v[i] == 0){
                for(int j = 1; j <= m; j++){
                    dp[0][j] = 1;
                }
            }
            else{
                dp[0][v[0]] = 1;
            }
        }
        else if(v[i] == 0){
            for(int j = 1; j <= m; j++){
                if(j < m){
                    dp[i][j+1] += dp[i-1][j];
                    dp[i][j+1] %= MOD;
                }     
                if(j > 1){
                    dp[i][j-1] += dp[i-1][j];
                    dp[i][j-1] %= MOD;
                }
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= MOD;
            }
        }
        else{
            dp[i][v[i]] += dp[i-1][v[i]-1];
            dp[i][v[i]] += dp[i-1][v[i]];
            dp[i][v[i]] %= MOD;
            if(v[i] < m){
                dp[i][v[i]] += dp[i-1][v[i] + 1];
                dp[i][v[i]] %= MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        // cout <<i << " " << dp[n-1][i] << " ";
        ans += dp[n-1][i];
        ans %= MOD;
    }
    cout << ans << "\n";
}
