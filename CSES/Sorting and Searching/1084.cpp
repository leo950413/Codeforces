#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<long> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;

    while (i < n && j < m){
        if (abs(a[i] - b[j]) <= k){
            ans++;
            i++;
            j++;
        }
        else if (b[j] < a[i] - k){
            j++;  
        }
        else{
            i++; 
        }
    }

    cout << ans << "\n";
}
