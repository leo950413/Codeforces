#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int c = 0;
    int idx = -1;

    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            c++;
            idx = i;
        }
    }

    if (c == 0) {
        cout << 0;
    } 
    else if (c == 1 && v[n - 1] <= v[0]) {
        cout << n - 1 - idx;
    } 
    else {
        cout << -1;
    }

    return 0;
}