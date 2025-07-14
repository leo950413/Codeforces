#include<iostream>
typedef long long ll;
using namespace std;
ll MAX = 1e16;

ll cnt(ll x)
{
    ll ans = 0;
    for (int i = 2;1ll * i * i * i <= x;++i)
        ans += x / (1ll * i * i * i);
    return ans;
}


int main(){
    ll n;
    cin >> n;
    ll l = 0, r = MAX;
    while (r >= l){
        ll mid = l + (r-l) /2;
        // cout << cnt(mid) << "\n";
        if(cnt(mid) >= n){
            r = mid -1;
        }
        else{
            l = mid + 1;
        }
    }
    // cout << cnt(l) <<"\n";
    if(cnt(l) == n){
        cout << l << "\n";
    }
    else{
        cout << -1 << "\n";
    }
    
}