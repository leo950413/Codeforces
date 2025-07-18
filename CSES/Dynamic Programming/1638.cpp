#include<iostream>
#include<vector>

using  namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<char>>v(n , vector<char>(n));
    vector<vector<int>>dp(n , vector<int>(n , 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (v[i][j] == '*'){
                dp[i][j] = 0;
            }
            else{
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0){
                    dp[i][j] = dp[i][j-1];
                }
                else if(j == 0){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
            dp[i][j] %= (int)(1e9 + 7);
            // cout << dp[i][j] << "\n";
        }
    }
    if(v[n-1][n-1] == '*')cout << "0\n";
    else cout << dp[n-1][n-1] << "\n";
}