#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n), s(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) cin >> s[i];

        if (n == 1) {
            if (p[0] == s[0]) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }

        int full_gcd = s[0];
        if (full_gcd != p[n-1]) {
            cout << "NO\n";
            continue;
        }

        bool ok = true;
        for (int i = 1; i < n; i++) {
            if(p[i] > p[i-1] || p[i-1] % p[i]){
                ok = false;
                break;
            }
            if(s[i] < s[i-1] || s[i] % s[i-1]){
                ok = false;
                break;
            }
            if (gcd(p[i - 1], s[i]) != full_gcd) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
