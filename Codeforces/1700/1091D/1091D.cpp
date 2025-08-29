#include <iostream>
#include <vector>
using namespace std;

const int mod = 998244353;

long long qk(long long a, long long n) {
    long long ans = 1;
    a %= mod;
    while (n) {
        if (n & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<long long> factorial(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = (factorial[i - 1] * i) % mod;
    }

    long long ans = factorial[n];
    for (int i = 1; i <= n - 2; i++) {
        long long term = factorial[n];
        term = (term * qk(factorial[n - i], mod - 2)) % mod; 
        term = (term * ((factorial[n - i] - 1 + mod) % mod)) % mod;
        ans = (ans + term) % mod;
    }

    cout << ans << "\n";
    return 0;
}
