#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<char> v(s.begin(), s.end());
    int t;
    cin >> t;

    int idx = 0;
    while (t && idx < v.size()) {
        int mx_id = idx;
        for (int i = idx + 1; i < v.size() && i - idx <= t; i++) {
            if (v[i] > v[mx_id]) {
                mx_id = i;
            }
        }

        for (int i = mx_id; i > idx; i--) {
            swap(v[i], v[i - 1]);
        }

        t -= (mx_id - idx);
        idx++;
    }

    for (char c : v) cout << c;
    cout << "\n";
}
