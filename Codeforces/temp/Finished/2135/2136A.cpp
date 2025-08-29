#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(min(a, b) * 2 + 2 < max(a,b)){
        cout << "NO\n";
        return;
    }
    c -= a;
    d -= b;
    if(min(c,d) * 2 + 2 < max(c , d)){
        cout << "NO\n";
        return;
    }
    cout<<"YES\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}