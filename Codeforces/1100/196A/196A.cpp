#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    string result;
    char max_char = 'a' - 1;

    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] >= max_char) {
            result += s[i];
            max_char = s[i];
        }
    }

    reverse(result.begin(), result.end());
    cout << result << "\n";
}
