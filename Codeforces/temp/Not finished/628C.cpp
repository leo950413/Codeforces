#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
vector<pair<int, int>> tree[MAXN];
long long a[MAXN];
bool is_sad[MAXN];

int dfs(int u, long long cur_sum, long long min_sum) {
    if (cur_sum - min_sum > a[u]) {
        is_sad[u] = true;
        return 0;
    }

    bool has_child = false;
    int leaf_count = 0;

    for (int i = 0; i < tree[u].size(); ++i) {
        int v = tree[u][i].first;
        int w = tree[u][i].second;

        long long next_sum = cur_sum + w;
        long long next_min = min(min_sum, next_sum);

        int sub = dfs(v, next_sum, next_min);
        leaf_count += sub;
        has_child = true;
    }

    if (!has_child) return 1;
    return leaf_count;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; ++i) {
        int p, c;
        cin >> p >> c;
        tree[p].push_back(make_pair(i, c));
    }

    int good_leaf_count = dfs(1, 0, 0);
    int total_leaf_count = 0;

    for (int i = 1; i <= n; ++i) {
        if (tree[i].empty()) total_leaf_count++;
    }

    cout << (total_leaf_count - good_leaf_count) << endl;

    return 0;
}
