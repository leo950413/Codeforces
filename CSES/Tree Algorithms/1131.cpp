#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>adj;
vector<int>dis;
void dfs(int u, int v, int dist){
    dis[u] = dist;
    for(auto child : adj[u]){
        if(child == v)continue;
        dfs(child, u ,dist + 1);
    }
}
int main(){
    int n;
    cin >> n;
    adj.resize(n+1);
    dis.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1 , 0);
    int mx = -1 , mx_id = 0;
    for(int i=1; i<=n; i++){
        if(dis[i] > mx)mx_id = i;
        mx = max(mx , dis[i]);
    }
    dfs(mx_id , -1 , 0);
    mx = -1;
    for(int i=1; i<=n; i++){
        mx = max(mx , dis[i]);
    }
    cout << mx << "\n";
}