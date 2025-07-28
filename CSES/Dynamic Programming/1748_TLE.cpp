#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    vector<int>dp(n+1 , 1); // all increasing subsequence end with v[i]

    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            if(v[i] > v[j])dp[i] += dp[j];
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans += dp[i];
    }
    cout << ans << "\n";
}