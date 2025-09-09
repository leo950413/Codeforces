#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;
        cout << n - temp + 1 <<" ";
    }
    cout << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}