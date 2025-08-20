#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int,int>> point;

void dfs(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]) dfs(v);
    }
}

int main(){
    int n;
    cin >> n;
    point.resize(n);
    for(int i=0;i<n;i++){
        cin >> point[i].first >> point[i].second;
    }
    adj.assign(n, vector<int>());
    visited.assign(n, false);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(point[i].first == point[j].first || point[i].second == point[j].second){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans - 1 << endl;
}
