#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    int t = n * m;
    vector<int> v(t);

    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }

    int target = v[0] % d;
    if (target < 0) target += d; 

    for (int i = 1; i < t; i++) {
        int cur = v[i] % d;
        if (cur < 0) cur += d;
        if (cur != target) {
            cout << "-1" << endl;
            return 0;
        }
    }

    sort(v.begin(), v.end());
    int median = v[t / 2];

    long long ans = 0;
    for (int i = 0; i < t; i++) {
        ans += abs(v[i] - median) / d;
    }

    cout << ans << endl;

    return 0;
}