#include<iostream>
#include<vector>
#include<climits>
using namespace std;
const long long V = 1e9;
void solve(){
    long long mx2  = -LLONG_MAX , mn1 = LLONG_MAX;
    long long n;
    cin >> n;
    for(int i=0; i<n; i++){
        long long x,y;
        cin >> x >> y;
        mx2 = max(mx2 , x + y);
        mn1 = -max(-mn1 , x - y);
    }
    // cout << a << " " << b << "\n";
    cout << "? R " << V << endl;
    cin >> n;
    cout << "? R " << V << endl;
    cin >> n;
    cout << "? D " << V << endl;
    cin >> n;
    cout << "? D " << V << endl;
    cin >> n;
    long long p = mn1 - n + 4L*V;
    cout << "? U " << V << endl;
    cin >> n;
    cout << "? U " << V << endl;
    cin >> n;
    cout << "? U " << V << endl;
    cin >> n;
    cout << "? U " << V << endl;
    cin >> n;
    long long q = mx2 + n - 4L*V;
    cout << "! " << (q - p) / 2 << ' ' << (q + p) / 2 << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}