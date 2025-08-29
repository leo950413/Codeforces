#include<iostream>
#include<vector>

using namespace std;
void solve(){
    // For every leaf, we need to perform one operation
    // unless the leaf is directly connected to the chosen central node u
    int n;
    cin >> n;
    vector<vector<int>>adj(n+1);
    // vector<int>leaf;
    int ans = 1e9;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int leaf = 0;
    for(int i=1; i<=n; i++){
        if(adj[i].size() == 1)leaf++;
    }
    // cout << leaf << " ";
    if(leaf == n-1 || n == 2){
        cout << "0\n";
        return;
    }
    for(int i=1; i<=n; i++){
        if(!adj[i].size()){
            // If central is leaf
            ans = min(ans ,leaf - 1);
        }
        else{
            int adj_root = 0;
            for(auto n : adj[i]){
                if(adj[n].size() == 1){
                    adj_root++;
                }
            }
            ans = min(ans ,leaf - adj_root);
        }
    }
    cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}