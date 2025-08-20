#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
// topological sort
using namespace std;
const int mx = 1e3 + 1;
vector<vector<bool>>g(mx , vector<bool>(mx));
bool cmp(int x, int y){
    if(g[x][y]) return x < y;
    else return x > y;
}
void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char t;
            cin >> t;
            g[i][j] = t-'0';
        }
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    sort(p.begin(), p.end(), cmp);
    for(auto n : p){
        cout << n << " ";
    }
    cout <<"\n";
}
int main(){
    int t;
    cin >> t; 
    while(t--){
        solve();
    }
}