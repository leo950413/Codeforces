#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    bool duplicate = 0;
    int i=0;
    for(; i<v.size()-1; i++){
        if(v[i] == v[i+1])duplicate=1;
    }
    if(!duplicate)cout << "NO\n";
    else cout << "YES\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}