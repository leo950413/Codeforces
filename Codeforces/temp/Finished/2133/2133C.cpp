#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int mx = -1;
    vector<vector<int>> layers(n + 1);
    vector<int> path;

    for (int i = 0; i < n; i++) {
        cout << "? " << i + 1 << " " << n << " ";
        for (int j = 1; j <= n; j++) {
            cout << j << (j == n ? '\n' : ' ');
        }
        cout.flush();

        int ans;
        cin >> ans;

        layers[ans].push_back(i + 1);

        if (ans > mx) {
            mx = max(ans , mx);
            path = {i + 1};
        }
    }

    for (int depth = mx - 1; depth > 0; depth--) {
        for (int candidate : layers[depth]) {
            cout << "? " << path.back() << " 2 " << path.back() << " " << candidate << "\n";
            cout.flush();

            int ans;
            cin >> ans;
            if (ans == 2) {
                path.push_back(candidate);
                break;
            }
        }
    }

    cout << "! " << path.size() << " ";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i] << (i + 1 == (int)path.size() ? '\n' : ' ');
    }
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// first iterate over all nodes as possible starting points
// track the maximum depth (mx) and the node that achieves it
// mx node becomes start of longest path
// then go backwards: for each depth from mx-1 down to 1
// check which candidate connects to the last node in the current path
// if connected, append to path