#include<iostream>
#include<vector>

using namespace std;
vector<vector<pair<int, int>>>adj;
vector<int>v;
int ans = 0;
void dfs(int u, int p , int dis){
    if(v[u] < dis) return; // not include v[u] < dis
    ans++;
    for(auto ch : adj[u]){
        int node = ch.first;
        int d = ch.second;
        if(node == p)continue;
        int next_dis = max(dis + d , 0);
        dfs(node , u , next_dis);
    }
}
int main(){
    int n;
    cin >> n;
    v.resize(n+1);
    adj.resize(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    for(int i=2; i<=n; i++){
        int p,c;
        cin >> p >> c;
        adj[i].push_back({p , c});
        adj[p].push_back({i , c});
    }
    dfs(1, -1 , 0);
    cout << n-ans << "\n";
}