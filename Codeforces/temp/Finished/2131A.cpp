#include<iostream>
#include<vector>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int>a(n),b(n);
    for(int i=0; i<n; i++)cin >> a[i];
    for(int i=0; i<n; i++)cin >> b[i];
    int gap = 0;
    for(int i=0; i<n; i++){
        gap += max(a[i]-b[i] , 0);
    }
    cout << gap + 1 << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}