#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void solve(){
    int n, ans = 0;
    long long k;
    cin >> n >> k;
    bool finish = 0;
    vector<long long>v(n+1);
    for(int i=1; i<=n; i++)cin >> v[i];
    for(int i=0; i<63; i++){// iterate through 1 to 1e9 < 2 ^ 63
        bool find = 1;
        for(int j=1; j<=n; j++){
            if((v[j] >> i) & 1){ // if the last i bit is 0
                ans++;
                continue;
            }
            else{
                if(k >= (1LL << i)){
                    k -= 1LL<<i;
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}