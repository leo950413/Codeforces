#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

int dp[1000005][26];
int p[1000005][26];
int main(){
    int n,t;
    cin >> n >> t;
    string s;
    cin >> s;
    for(int i = 1; i<=s.size() + 1; i++){
        for(int j=0; j<t; j++){
            p[i][j] = -1;
        }
    }
     for(int i = 1; i<=s.size() + 1; i++){
        if(i == 1){
            for(int j=0; j<t; j++){
                if(j != s[0]-'A' ){
                    dp[i][j] = 1;
                }
            }
        }
        else{
            for(int j=0; j<t; j++){ // previous
                dp[i][j] = 1e9;
            }
        }
    }

    for(int i=1; i<=s.size(); i++){

        for(int j = 0; j<t; j++){// last
            for(int k = 0; k<t; k++){// current
                int m = s[i] - 'A';
                if(k == j){ // last = current
                    dp[i + 1][k] = min(10000000 , dp[i + 1][k]);
                }
                else if(k == m){ // not need to modify
                    if(dp[i][j] < dp[i+1][k]){
                        p[i+1][k] = j;
                        dp[i + 1][k] = min(dp[i][j] , dp[i + 1][k]);
                    }
                }
                else{
                    if(dp[i][j] + 1 <  dp[i + 1][k]){
                        p[i+1][k] = j;
                        dp[i + 1][k] = min(dp[i][j] + 1, dp[i + 1][k]);
                    }
                }
            }
        }
    }
    int mn = 1e9, mn_idx;;
    // for(int i=1; i<=s.size(); i++){
    //     for(int j=0; j<t; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i=0; i<t; i++){
        if(dp[n][i] < mn){
            mn_idx = i;
            mn = min(dp[n][i], mn);
        }
    }
    string ans;
    for(int i=s.size(); i>=1; i--){
        // cout << mn_idx << "\n";
        ans += 'A' + mn_idx;
        mn_idx = p[i][mn_idx];
    }
    reverse(ans.begin(), ans.end());
    cout << mn <<"\n" << ans << "\n";
}