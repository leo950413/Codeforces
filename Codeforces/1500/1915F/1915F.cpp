#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

ordered_set s;

void solve(){
    int n;
    long long ans = 0;

    cin >> n;

    vector<pair<int, int>>v(n);

    for(int i=0; i<n; i++)cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    s.clear();
    for(auto p : v){
        ans += s.size() - s.order_of_key(p.second);
        s.insert(p.second);
    }
    cout << ans <<"\n";

}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
