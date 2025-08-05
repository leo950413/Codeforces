#include<vector>
#include<iostream>
using namespace std;

const int MX = 1e5 + 1;
int n, m;
vector<vector<int>>adj(MX);
vector<bool>visited(MX, 0);
vector<int>bridges;

void bfs(int node){
    visited[node] = 1;
    for(auto &child : adj[node]){
        if(!visited[child]){
            bfs(child);
        }
    }
}
int main(){
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bridges.push_back(i);
            bfs(i);
        }
    }
    cout << bridges.size() - 1 << "\n";
    for(int i=0; i<bridges.size()-1; i++){
        cout << bridges[i] << " " << bridges[i+1] << "\n";
    }
}