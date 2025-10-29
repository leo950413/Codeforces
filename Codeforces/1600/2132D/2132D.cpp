#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<long long>crit;
void init(){
    long long curr = 0;
    crit.push_back(9);
    long long j = 9;
    for(long long i=1; i<=15; i++, j*=10){
        curr += j*i;
        crit.push_back(curr);
    }
}
void solve(){
    long long n;
    cin >> n;
    int l = 0, r = crit.size()-1;
    long long ans = 0;
    while (r >= l){
        int mid = (l + r)/2;
        if(crit[mid] < n){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << l << " " << crit[l] << " " << n << "\n";
    for(int i=1; i<l; i++){
        ans += 45 * i * (long long)pow(10, (i-1));
    }
    
    cout << ans << "\n";
    
}
int main(){
    init();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}