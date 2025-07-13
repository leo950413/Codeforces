#include <iostream>
#include <cmath>
using namespace std;

int removeFactors(int& x, int factor) {
    int count = 0;
    while (x % factor == 0) {
        x /= factor;
        count++;
    }
    return count;
}

int main() {
    int a, b;
    cin >> a >> b;

    int a2 = removeFactors(a, 2);
    int a3 = removeFactors(a, 3);
    int a5 = removeFactors(a, 5);

    int b2 = removeFactors(b, 2);
    int b3 = removeFactors(b, 3);
    int b5 = removeFactors(b, 5);

    if (a != b) {
        cout << -1 << endl;
        return 0;
    }

    int operations = abs(a2 - b2) + abs(a3 - b3) + abs(a5 - b5);
    cout << operations << endl;
    return 0;
}
