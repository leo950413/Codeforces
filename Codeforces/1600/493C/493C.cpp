#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    long long n, m;
    
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long best_a = 3 * n;
    long long best_b = 3 * m;
    long long diff = best_a - best_b;

    for(int i = 0; i < n; i++){
        int d = a[i];

        long long cnt3a = n - (lower_bound(a.begin(), a.end(), d) - a.begin());
        long long point_a = 2LL * (n  - cnt3a) + cnt3a * 3;

        long long cnt3b = m - (lower_bound(b.begin(), b.end(), d) - b.begin());
        long long point_b = 2LL * (m - cnt3b) + cnt3b * 3;
        // cout << cnt3a << " " << cnt3b << "\n";

        if(point_a - point_b > diff){
            diff = point_a - point_b;
            best_a = point_a;
            best_b = point_b;
        }
        else if(point_a - point_b == diff){
            if(point_a > best_a){
                best_a = point_a;
                best_b = point_b;
            }
        }
    }

    long long last_a = 2LL * n;
    long long last_b = 2LL * m;
    if(last_a - last_b > diff || (last_a - last_b == diff && last_a > best_a)){
        best_a = last_a;
        best_b = last_b;
    }

    cout << best_a << ":" << best_b << endl;

    return 0;
}