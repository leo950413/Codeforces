#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<long long>dp(5000, 0);
    dp[a] = 1;
    dp[b] = 1;
    dp[c] = 1;
    for(int i=1; i<=n; i++){
        if(i - a >= 0){
            if(dp[i-a] != 0){
                dp[i] = max(dp[i] , dp[i-a] + 1);
            }
        }
        if(i - b>=0){
            if(dp[i - b] != 0){
                dp[i] = max(dp[i] , dp[i-b] + 1);
            }
        }
        if(i - c>=0){
            if(dp[i-c] != 0){
                dp[i] = max(dp[i] , dp[i-c] + 1);
            }
        }
        // cout << dp[i] << " ";
    }
    cout << dp[n] << "\n";
}