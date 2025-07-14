#include<iostream>
#include<vector>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
ll dp[100][2] ={0};
int main(){
    int n,k,d;
    cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i=1; i<=n; i++){ 
        for(int j=1; j<=k; j++){
            if(i<j)break;
            if(j<d){
                dp[i][0] += dp[i-j][0];
                dp[i][1] += dp[i-j][1];
            }
            else{
                dp[i][1] += dp[i-j][0];
                dp[i][1] += dp[i-j][1];
            }
            dp[i][0] %= MOD;
            dp[i][1] %= MOD;            
        }
    }

    cout <<dp[n][1] << "\n";
}