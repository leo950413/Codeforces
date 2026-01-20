#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long s1 = 0,tx = 0,ty = 0;
    for (int i = 0; i < n; ++i) {
        int j = n - 1 - i;
        s1 += a[i];
        tx += i * a[i];
        ty += j * a[i];
    }


    int c = gcd(s1 + 2LL * (tx - ty), n);

    cout << (s1 + 2LL * (tx - ty)) / c << " " << n / c << endl;

    return 0;
}