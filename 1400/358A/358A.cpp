#include<iostream>
#include<vector>
using namespace std;

bool cross(long long a, long long b, long long c, long long d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);     
    return (a < c && c < b && b < d) ||
           (c < a && a < d && d < b);
}

int main() {

    int n;                 
    if (!(cin >> n)) return 0;
    vector<long long> x(n);
    for (auto &v : x) cin >> v;

    for (int i = 0; i + 1 < n; ++i)
        for (int j = i + 2; j + 1 < n; ++j)
            if (cross(x[i], x[i + 1], x[j], x[j + 1])) {
                cout << "yes\n";
                return 0;
            }
    cout << "no\n";
}
