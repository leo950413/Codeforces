#include<iostream>
#include<vector>
using namespace std;

vector<int>v;
vector<vector<int>>adj;
void dfs(int u , int p, bool flip){
    for(auto c : adj[u]){
        if(c == p)continue;
            
    }


}
int main(){
    int n;
    cin >> n;
    adj.resize(n+1);
    v.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

}
