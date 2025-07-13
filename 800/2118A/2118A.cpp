#include<iostream>
#include<vector>

using namespace std;

void solve(){
    int n,k;
    cin >> n >>  k;
    string ans;
    if(n==k || k == 0){
        for(int i=0; i<n; i++){
            cout  << (k==0 ? 0 : 1);
        }
        cout  << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        k -= 1;
        if(k >= 0){
            cout << "1";
        }
        else{
             cout << "0";
        }
    }
    cout << "\n";
    // cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}