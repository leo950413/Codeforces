#include<iostream>
#include<vector>
using namespace std;

int main(){
    // given example 11 22 333 44
    // f(1) = 1 * 2 = 2
    // f(2) = 2 * 2 = 4
    // f(3) = max(f(2) , f(1) + 3 * cnt(3))
    // f(4) = max(f(3) , f(2) + 4 * cnt(4))
    int n;
    cin >> n;
    vector<long long>cnt(100001, 0) , dp(100001, 0);
    int t;
    while(n--){
        cin >> t;
        cnt[t] += 1;
    }
    dp[0] = 0;
    dp[1] = cnt[1]; 
    for(int i=2; i<dp.size(); i++){
        dp[i] = max(dp[i-1] , i * cnt[i] + dp[i-2]);
    }
    cout << dp.back() << "\n";
}