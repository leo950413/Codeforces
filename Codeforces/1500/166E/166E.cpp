#include<iostream>
#include<vector>
#define ll long long
const ll MOD = 1e9 + 7;
using namespace std;
int main(){
    ll n;
    cin >> n;
    ll abc = 0 , d = 1;
    for(int i=0; i<n; i++){
        ll n_abc , n_d;
        n_d = (abc * 3) % MOD;
        n_abc = (abc * 2 + d) % MOD;
        d = n_d;
        abc = n_abc;
    }
    cout << d << "\n";
}