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
    int mx =  *max_element(v.begin() , v.end());
    if(init_h == mx){
        cout << "yes\n";
        return;
    }
    v.erase(unique(v.begin() , v.end()), v.end());
    int i = find(v.begin() , v.end() ,init_h) - v.begin();
    for(; i+1<v.size(); i++){
        
        if(v[i+1] - v[i] > init_h){
            cout << "NO\n";
            return;
        }
    }
    cout << "yes\n";
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}