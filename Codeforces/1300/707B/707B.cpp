#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 1e5 + 7;

int main() {


    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, long long>>> adj(n + 1);
    vector<int> vis(n + 1, 0);
    vector<int> a(k + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    if (k == 0 || k == n) {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
    }

    long long ans = 1e18;

    for (int u = 1; u <= n; u++) {
        if (vis[u]) continue;
        for (auto p : adj[u]) {

            if (vis[p.first]) {
                ans = min(ans, p.second);
            }
        }
    }

    if(ans == 1e18){
        cout << -1 << "\n";
    } 
    else {
        cout << ans << "\n";
    }
}
