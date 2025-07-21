#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>>v(n);
    for(int i=0; i<n; i++){
        int l,r,real;
        cin >> l >> r >> real;
        v[i].first=l,v[i].second=real;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        if(k < v[i].first){
            break;
        }
        else if(v[i].second > k){
            k = v[i].second;
        }
    }
    cout << k << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}