#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>adj;
vector<int>vis;
int cnt = 0;
void dfs(int u){
    if(vis[u])return;
    vis[u] = 1;
    cnt++;
    for(auto c : adj[u]){
        dfs(c);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    vis.resize(n+1, false);
    if(n!=m){ // the vertices and edges of a ring must be equal
        // and add another veritces will cost an edge
        cout << "NO\n";
        return 0;
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    if(cnt == n){// if all vertic is connected
        cout << "FHTAGN!\n";
    }
    else{
        cout <<"NO\n";
    }
    // cout << cnt << "\n";
}