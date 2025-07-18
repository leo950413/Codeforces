#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(){
    int n, k , init_h;
    cin >> n >>k;
    vector<int>v(n), r(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(i + 1 == k){
            init_h = v[i];
        }
    }
    sort(v.begin() ,v.end());

    int i = find(v.begin() , v.end() ,init_h) - v.begin();
    int prev = v[i],water = 1;
    while(i<n){
        while(v[i] == prev){
            i++;
        }
        if(v[i] - prev > prev - water + 1){
            cout << "No\n";
            return;
        }
        prev = v[i];
        water++;
    }
    cout << "yes\n";
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}