#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int SIZE = 1e6;
const int MOD = 1e9 + 7;
int dp[SIZE] = {0};

int main(){
    int n,x;
    cin >> n >> x;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    dp[0] = 1;
    for(auto e:v){
        for(int i=1; i<=x; i++){
            if(i >= e){
                dp[i] += dp[i-e];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[x] << "\n";
}