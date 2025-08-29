#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;


vector<long long>power_three;


long long calc(int x){
    return pow(3ll, x+1) + x*pow(3ll, x-1);
}
void solve(){
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    vector<pair<int , int>>v(power_three.size());
    // cout << calc(x) << " ";
    for(int i=0; i<(int)power_three.size();i++) {
        v[i]={i, 0};
    }

    while(n>0){
        if(k == 0){
            cout << "-1\n";
            return;
        }
        int x = upper_bound(power_three.begin(), power_three.end() ,n)-power_three.begin()-1;
        // cout << x << " ";
        ans += calc(x);
        n-=power_three[x];
        v[x].second++;
        k--;
    }
    for(int i=power_three.size()-1; i>0 && k >= 2; i--){
        if(v[i].second == 0)continue;
        int times = min(k/2, v[i].second);
        v[i-1].second += 3 * times;
        k -= times * 2;
        ans -= power_three[i-1] * times;
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