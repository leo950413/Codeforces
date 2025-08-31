#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
      cin >> i;

    vector<int> b(n + 1);
    long long ans = 0;
    for (int i = 0; i < n; i += 2) {
      int mn = a[i];
      if (i >= 2)
        mn = min(mn, a[i - 1] - b[i - 2]);
      if (i + 1 < n)
        mn = min(mn, a[i + 1]);
      b[i] = mn;
      ans += (a[i] - b[i]);
    }

    cout << ans << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}