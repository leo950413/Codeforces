#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> p(n+1);
    vector<long long> prefix(n+1, 0);
    int ss=0;
    for(int i=1; i<=n; i++){
        cin >> p[i];
        prefix[i] = prefix[i-1] + p[i];
    }
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));

    for (int i = m; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            // not taking the m-sized segment ending here
            dp[i][j] = dp[i-1][j];
            // taking the m-sized segment ending at i
            dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + prefix[i] - prefix[i - m]);
        }
    }
    cout << dp[n][k] << endl;
}