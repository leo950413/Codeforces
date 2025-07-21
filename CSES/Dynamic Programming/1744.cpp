#include<iostream>
using namespace std;
int dp[501][501];

int main(){
    int a,b;
    cin >> a >> b;
    for(int i=0; i<501; i++){
        for(int j=0; j<501; j++){
            dp[i][j] = 1e9;
        }
    }
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i == j){
                dp[i][j] = 0;
            }
            for(int k=1; k<j; k++){
                dp[i][j] = min(dp[i][j] , dp[i][j-k] + dp[i][k] + 1);
            }
            for(int k=1; k<i; k++){
                dp[i][j] = min(dp[i][j] , dp[i-k][j] + dp[k][j] + 1);
            }
        }
    }
    cout << dp[a][b] << "\n";
}
