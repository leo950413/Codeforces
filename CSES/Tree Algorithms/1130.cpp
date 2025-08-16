#include<iostream>
#include<vector>

using namespace std;
#define ll long long
const ll INF = 10000000000000;
const ll MX = 2e5 + 5;

vector<ll> adj[MX+1];
ll dp[2][MX+1];
void dfs(ll u , ll p){
    dp[0][u] = 0;
    dp[1][u] = -INF;
    for(auto v : adj[u]){
        if(v == p){
            continue; // 1 -> 2 -> 1
        }
        dfs(v , u);
        // exclude node u
        dp[0][u] += max(dp[0][v] , dp[1][v]);
        // include node u
        ll opt = min(dp[0][v] - dp[1][v],0LL);
        // choose a child that bring more pairs
        dp[1][u] = max(dp[1][u], opt);
    }
    // Add pairs without the current node
    dp[1][u] += dp[0][u];
    dp[1][u] ++; // add u + child pair
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    cout << max(dp[0][1], dp[1][1]);
}