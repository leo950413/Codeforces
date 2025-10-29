#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    int idx =1, curr = 0, mx = 0;
    vector<int>v(n+1 , -1);
    vector<int>rec;
    for(int i =1; i<=n; i++){
        char c;
        cin >> c;
        if(c == '1'){
            v[i] = idx;
            idx++;
            curr++;
        }
        else if(curr > 0){
            mx = max(curr ,mx);
            curr = 0;
        }
    }
    mx = max(curr ,mx);
    if(mx >= k || (mx && (k == 1))){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i=1; i<=n; i++){
        if(v[i] == -1){
            v[i] = idx;
            idx++;
        }
    }
    for(int i=1; i<=n; i++){
        cout << v[i] << " ";
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