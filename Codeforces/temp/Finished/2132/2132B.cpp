#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector<long long>ans;
    for(long long i=10; i<=n; i*=10){
        if(n % (i+1) == 0){
            ans.push_back(n/(i+1));
        }
    }
    sort(ans.begin() , ans.end());
    cout << ans.size() << "\n";
    if(ans.size()){
        for(auto i : ans)cout << i << " ";
        cout << "\n";
    }
    // return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}