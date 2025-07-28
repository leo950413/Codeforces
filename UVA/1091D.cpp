#include<iostream>
#include<vector>
#include <iomanip>
#include<cmath>

using namespace std;

int main(){
    vector<int>coins({5, 10  ,20 ,50, 100, 200, 500, 1000 , 2000 ,  5000, 10000});
    float t;
    cin >> t;
    vector<long long>dp(30000+1 , 0);
    dp[0] = 1;
    for(int i=0; i<coins.size(); i++){
        for(int j=1; j<=30001; j++){
            if(coins[i] <= j)dp[j] += dp[j-coins[i]];
            // cout << dp[j] << "\n";
        }
    }
    while(t != 0.0){
        int nt = round(t * 100);
        cout << setw(6) << fixed << setprecision(2) << t
             << setw(17) << dp[nt] << "\n";
        cin >> t;
    }
}