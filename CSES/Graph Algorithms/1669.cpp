#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int MAXN = 1e5;
int e = 0;
vector<vector<int>>adj(MAXN+1);
vector<int>visited(MAXN+1 , 0);
vector<int>parent(MAXN+1);
bool cycle(int cur,  int p){
    parent[cur] = p;
    visited[cur] = 1;
    for(auto child : adj[cur]){
        if(child != p && visited[child]){
            parent[child] = cur;
            e = cur;
            return true;
        }
        if(!visited[child]){
            if(cycle(child , cur)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int i=1 ,find = 0;
    for(; i<=n; i++){
        if(!visited[i]){
            if(cycle(i , -1)){
                find |= 1;
                break;
            }
        }
    }
    if(!find){
        cout<<"IMPOSSIBLE\n";
        exit(0);
    }
    vector<int>ans;
    ans.push_back(e);
    int curr = parent[e];
    while(curr != e){
        ans.push_back(curr);
        curr = parent[curr];
    }
    ans.push_back(e);
    
    cout << ans.size() << "\n";
    for(auto & i : ans){
        cout << i << " ";
    }
}