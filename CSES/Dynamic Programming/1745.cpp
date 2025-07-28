#include<iostream>
#include<vector>
using namespace std;
int const mx = 1e6;
int dp[mx+1] = {0};
int main(){
    int n, s = 0;
    vector<int>temp;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        s += v[i];
    }
    int ans =  0;
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=s; j>=v[i]; j--){
            if(!dp[j])dp[j] = dp[j - v[i]];
        }
    }
    for(int i=1; i<=s; i++){
        if(dp[i]){
            ans++;
        }
    }
    cout << ans << "\n";
    for(int i=1; i<=s; i++){
        if(dp[i]){
            cout << i << " ";
        }
    }
}