#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void solve(){
    long long a,b;
    cin >> a >> b;
    long long t_b = b;
    int two_cnt = 0;
    while(t_b % 2 == 0){
        t_b/=2;
        two_cnt++;
    }
    // if b is odd -> best is a*b+1
    if(two_cnt == 0){
        if(a % 2 == 0)cout << "-1\n";
        else cout << a* b + 1 << "\n";
    }
    // 
    else if(two_cnt == 1){
        if(a%2 == 1)cout << "-1\n";
        else cout << a*b/2 + 2 << "\n";
    }
    else{
        long long ans = -1;
        for(int i=1; i<two_cnt; i++){
            long long curr = a*b/(1LL << i) + (1LL << i);
            ans = max(curr ,ans);
        }
        cout << ans << "\n";
    }

}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}