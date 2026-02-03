#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int MOD = 1e9 + 7;
int dp[5001][5001];
int main(){
    string s;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char temp;
        cin >> temp;
        s += temp;
    }
    dp[0][0] = 1;
    for(int i=0; i<n-1; i++){
        if(s[i] == 'f'){
            for(int j=0; j<n; j++){
                dp[i + 1][j + 1] = dp[i][j];
            }
        }
        else{
            long long sp = 0;
            for(int j=n-1; j>=0; j--){
                sp = (sp + dp[i][j]) % MOD;
                dp[i + 1][j] = (dp[i + 1][j] + sp) % MOD;
            }
        }
    }
    long long ans = 0;
    for(int j = 0; j < n; j++){
        ans = (ans + dp[n - 1][j]) % MOD;
    }

    cout << ans;
}