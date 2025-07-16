#include<vector>
#include<iostream>
#include<algorithm>
#include<climits>
const int MX = 1e6;
int dp[MX];
using namespace std;
int main(){
    int n,x; 
    cin >> n >> x;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin() , v.end());
    fill(dp, dp + x + 1, INT_MAX - 1);
    dp[0] = 0;
    for(int i=1; i<=x; i++){
        for(int j=0; j<v.size(); j++){
            // cout << i << " " << dp[i] << " " << v[j] << "\n";
            if(i > v[j]){
                dp[i] = min(dp[i-v[j]] + 1 , dp[i]);
            }
            else if(i == v[j]){
                dp[i] = 1;
            }
        }
    }
    if(dp[x] == INT_MAX-1){
        cout << "-1\n";
    }
    else{
        cout << dp[x];
    }
    

}