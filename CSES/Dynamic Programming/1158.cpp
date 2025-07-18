#include<iostream>
#include<vector>

using namespace std;
int dp[(int)1e5+1] = {0};
int main(){
    int n,x;
    cin >> n >> x;
    vector<int>h(n),s(n);
    for(int i=0; i<n; i++)cin>>h[i];
    for(int i=0; i<n; i++)cin>>s[i];
    for(int j=0; j<h.size(); j++){
        for(int i=x; i>0; i--){
            if(i >= h[j]){
                dp[i] = max(dp[i] , dp[i-h[j]] + s[j]);
            }
        }
        // cout << dp[i] << "\n";
    }
    cout << dp[x] << "\n";
}