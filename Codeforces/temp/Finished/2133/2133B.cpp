#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int>v(n);
    long long ans = 0;
    for(int i=0; i<n; i++)cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    for(int i=0; i<n; i+=2){
        if(i+1 < n)ans += max(v[i], v[i+1]);
    }
    if(n%2)ans += v[n-1];
    cout << ans <<  "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
