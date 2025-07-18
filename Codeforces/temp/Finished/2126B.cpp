#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n , k , ans = 0;
    cin >> n >> k;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int i=0 , prev = v[0];
    while(true){
        if(i == n){
            break;
        }
        int c = 0;
        while(i<n){
            if(v[i] == prev && c<=k){
                i++;
                c++;
            }
            else{
                break;
            }
        }
        i--;
        // cout << prev << " " << i <<  " "<<ans << "\n";
        if(!prev){ //prev = 0
            if(c >= k){
                ans ++;
            }
        }
        i++;
        prev = v[i];
    }
    cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}