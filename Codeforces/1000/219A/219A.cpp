#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int k;
    string s;
    cin >> k >> s;

    map<char, int> cnt;
    for (char ch : s) {
        cnt[ch]++;
    }

    string s1;
    bool ok = true;
    for (auto &p : cnt) {

        if (p.second % k != 0) {
            ok = false;
            break;
        }
        s1.append(p.second / k, p.first);
    }

    if (!ok) {
        cout << -1 << endl;
        return 0;
    }

    while (k--) {
        cout << s1;
    }
    cout << "\n";

    return 0;
}
