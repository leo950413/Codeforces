#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int gcd(int a, int b) {
    int res = min(a, b);
    while (res > 1) {

        if (a % res == 0 && b % res == 0)
            break;
        res--;
    }
	return res;
}
void solve(){
    int n,k;
    cin >> n >> k;
    int g = -1;
    for(int i=2; i<=100; i++){
        // g is going to be at most 29
        // 2 * 3 * 5 ... * 29 + 1 > 1e9 
        if(gcd(i , k) == 1){
            g = i;
            break;
        }
    }
    vector<long long>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    if(g != -1){
        for(auto &t : v){
            while(t % g != 0){
                t += k;
            }
        }
    }
    // g also works for g = k + 1
    for(int i=0; i<n; i++)cout << v[i] << " ";
    cout << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}