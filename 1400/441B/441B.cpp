#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n, m;                     
    cin >> n >> m;

    vector<int> a(3005);         
    for (int i = 0, d, c; i < n; ++i) {
        cin >> d >> c;          
        a[d] += c;
    }

    long long ans = 0;         
    for (int i = 1; i < (int)a.size(); ++i) {
        int y = min(a[i - 1], m);
        ans += y;

        int t = min(a[i], m - y);  
        ans += t;
        a[i] -= t;               
    }
    ans += min(a.back(), m);   

    cout << ans << '\n';
}
