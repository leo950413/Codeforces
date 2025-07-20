#include<vector>
#include<iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int>v1(n),v2(m);
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0)),prev(n+1, vector<int>(m+1 , 0));
    for(int i=0; i<n; i++)cin >> v1[i];
    for(int i=0; i<m; i++)cin >> v2[i];
    for(int i=0; i<n+1; i++)dp[i][0] = 0;
    for(int i=0; i<m+1; i++)dp[0][i] = 0;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){ // make mark for backtrack
            if(v1[i-1] == v2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                prev[i][j] = 0;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                prev[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i][j-1];
                prev[i][j] = 2;
            }
        }
    }
    cout << dp[n][m] << "\n";
    int len = dp[n][m],i = n,j = m;// start from dp[n][m]
    vector<int>ans(len);
    while(len > 0){
        if(prev[i][j] == 0){
            len--;
            ans[len] = v1[i-1];
            i--;
            j--;
        }
        else if(prev[i][j] == 1){
            i--;
        }
        else{
            j--;
        }
    }
    for(int c:ans){
        cout << c << " ";
    }
}