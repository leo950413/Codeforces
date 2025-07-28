#include<iostream>
#include<vector>
using namespace std;

int main(){
    // dp solution O(n^2)
    // need O(nlogn) solution
    int n;
    cin >> n;
    vector<int>v(n , 0), dp(n , 1);
    for(int i=0; i<n; i++)cin >> v[i];
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(v[i] < v[j]){
    //             dp[j] = max(dp[j], dp[i]+1);
    //         }
    //         // cout << dp[j] << " ";
    //     }
    //     // cout << "\n";
    // }
    // int mx = 0;
    // for(int i=0; i<n; i++){
    //     mx = max(mx, dp[i]);
    // }
    // cout << mx << "\n";
    vector<int>ans;
    for(int i=0; i<n; i++){
        if(ans.empty() || v[i] > ans.back()){
            ans.push_back(v[i]);
        }
        else{
            *lower_bound(ans.begin() , ans.end() , v[i]) = v[i];
        }
    }
    cout << ans.size() << "\n";
}