#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1);
    vector<int>parent(n+1);
    vector<bool>visited(n+1 , 0);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool find = 0;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto child : adj[node]){
            if(!visited[child]){
                parent[child] = node;
                q.push(child);
                visited[child] = 1;
            }
            if(child == n){
                find = 1;
            }
        }
        if(find){
            break;
        }
    }
    if(!find){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int cur = n;
    vector<int>ans;
    while(cur != 1){
        ans.push_back(cur);
        cur = parent[cur];
    }
    ans.push_back(1);
    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for(auto num : ans){
        cout << num << " ";
    }
}