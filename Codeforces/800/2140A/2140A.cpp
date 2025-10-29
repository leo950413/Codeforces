#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int>v(n);
    int one_cnt=0 , zero_cnt=0;
    for(int i=0; i<n; i++){
        char c;
        cin >> c;
        v[i] = c - '0';
        if(v[i])one_cnt++;
        else zero_cnt++;
    }
    int ans = 0;
    for(int i=0; i<zero_cnt; i++){
        if(v[i] == 1)ans++;
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