#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1);
    vector<int>visited(n+1);
    vector<int>side(n+1, -1); 
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int>q;
    bool possible = 1;
    for(int i=1; i<=n; i++){
        if(side[i] == -1){
            q.push(i);
            // cout << q.front() << "\n";
            side[i] = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto child : adj[node]){
                    if(side[child] == -1){
                        side[child] = side[node]^1; // 1 -> 0 || 0 -> 1
                        q.push(child);
                    }
                    if(side[child] == side[node]){
                        possible = 0;
                    }
                }
            }
        }
        if(!possible){
            break;
        }
    }
    if(!possible){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i=1; i<=n; i++){
        cout << side[i]+1 << " ";
    }
}