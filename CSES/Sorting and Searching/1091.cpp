#include <iostream>
#include <set>
#include <algorithm>
#include<vector>
using namespace std;

int main(){
    long n, m, ans = 0;
    cin >> n >> m;
    multiset<long>a;
    vector<long>b(m);

    for(int i = 0; i < n; i++){
        long x;
        cin >> x;
        a.insert(x);
    }
    for(int i = 0; i < m; i++) cin >> b[i];

    for(int i=0; i<m; i++){
        auto it = a.upper_bound(b[i]);
        if(it==a.begin()){
            cout << "-1\n";
        }
        else{
            it--;
            cout << *it << "\n";
            a.erase(it);
        }
    }

    // cout << ans << "\n";
}
