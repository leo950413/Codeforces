#include<iostream>
#include<vector>
#include<math.h>
#include<string>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector<int>divisor;
    for(int i=1; i*i<=n; i++){
        if(n % i == 0){
            divisor.push_back(i);
            if(i != n/i) divisor.push_back(n/i);
        }
    }
    divisor.push_back(0);
    divisor.push_back(n-1);
    for(auto d : divisor){
        for(int i=0; i<9; i++){
            long long p10 = 1;
            for (int j=0; j<i; j++) p10 *= 10;
            long long ans = ((p10 - d - 2LL) / (d+1LL)) * n;
            if (ans > 0) {
                long long len = to_string(ans).size();
                long long p10 = 1;
                for (int j=0; j<len; j++) p10 *= 10;

                long long concat = n * p10 + ans;
                if (concat % (ans + n) == 0 && ans < 1e9) {
                    cout << ans << "\n";
                    return;
                }
            }

        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}