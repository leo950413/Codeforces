#include<vector>
#include<iostream>
#define ll long long
using namespace std;

int main(){
    ll n,t;
    cin >> n >> t;
    vector<ll>vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    int ans = 0 , j =0;
    ll s = 0;
    for(int i=0; i<n;i++){
        while(j < n && s + vec[j] <= t){
            s += vec[j];
            j++;
        }
        ans = max(ans, j - i);
        s -= vec[i];
    }
    cout << ans << '\n';
}
