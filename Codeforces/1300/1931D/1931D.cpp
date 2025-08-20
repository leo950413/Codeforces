#include<iostream>
#include<map>
#include<vector>

using namespace std;

void solve(){
    map<pair<int ,int> , long long>m;
    vector<int>v;
    int n,x,y;
    long long ans=0;
    cin >> n >> x >> y;
    while(n--){
        int a;
        cin >> a;
        v.push_back(a);
    }
    for(auto n : v){
        int a_x = n % x;
        int a_y = n % y;
        ans += m[{(x - a_x)%x, a_y}];
        m[{a_x, a_y}]++;
    }
    cout << ans << "\n";

}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}