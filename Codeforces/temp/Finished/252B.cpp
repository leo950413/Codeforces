#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 2) {
        cout << -1 << endl;
        return 0;
    }

    int a[100005], b[100005], c[100005];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        c[i] = a[i];
    }

    sort(b, b + n);
    if (b[0] == b[n - 1]) {
        cout << -1 << endl;
        return 0;
    }

    sort(c, c + n, greater<int>()); 

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) continue; 

        for (int j = i + 1; j < n; ++j) {
            if (a[j] == a[j - 1]) continue; 
            if (a[i] == a[j]) continue;     

            if ((a[j] != b[i] || a[i] != b[j]) &&
                (a[i] != c[j] || a[j] != c[i])) {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
