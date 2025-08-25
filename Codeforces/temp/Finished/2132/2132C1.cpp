#include<algorithm>
#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
vector<long long>power_three;


long long calc(int x){
    return pow(3ll, x+1) + x*pow(3ll, x-1);
}
void solve(){
    int n;
    cin >> n;
    long long ans = 0;
    // cout << calc(x) << " ";
    while(n>0){
        int x = upper_bound(power_three.begin(), power_three.end() ,n)-power_three.begin()-1;
        ans += calc(x);
        n-=power_three[x];
    }
    cout << ans << "\n";
}

int main(){
    for(long long i=1; i<=1e9+1; i*=3){
        power_three.push_back(i);
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}