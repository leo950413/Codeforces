#include<iostream>
#include<vector>
using namespace std;

vector<int>init;
vector<vector<int>>adj;
vector<int>goal;
vector<int>modified;
int op_time = 0;
void dfs(int u, int p , bool odd_flip, bool even_flip, int depth){

    if(depth % 2){
        int curr = init[u] ^ odd_flip;
        if(goal[u] != curr){
            odd_flip ^= 1;
            modified.push_back(u);
            op_time += 1;
        }
    }
    else{
        int curr = init[u] ^ even_flip;
        if(goal[u] != curr){
            even_flip ^= 1;
            modified.push_back(u);
            op_time += 1;
        }
    }
    for(auto c : adj[u]){
        if(c == p)continue;
        dfs(c, u, odd_flip,  even_flip, depth+1);
    }
}
int main(){
    int n;
    cin >> n;
    adj.resize(n+1);
    init.resize(n+1);
    goal.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;
        init[i] = temp;
    }
    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;
        goal[i] = temp;
    }

    dfs(1, NULL, 0 , 0, 0);
    cout << op_time << "\n";
    for(auto c : modified) cout << c << "\n";
}
