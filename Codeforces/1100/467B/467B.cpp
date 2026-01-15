#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long n,m,k;
    cin >> n >> m >> k;
    vector<int>v(m + 1);
    for(int i=0; i<=m; i++){
        cin >> v[i];
    }
    int ans = 0;
    for(int i=0; i<m; i++){
        int cnt = 0;
        int temp = v[m];
        while(temp!=0 || v[i]!=0){
            if(temp%2 != v[i]%2){
                cnt++;
            }
            v[i] >>= 1;
            temp >>= 1;
        }
        // cout << cnt << "\n";
        if(cnt <= k){
            ans++;
        }
    }
    cout << ans << "\n";
}