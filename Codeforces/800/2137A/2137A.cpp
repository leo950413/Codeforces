#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void solve(){
    long long k,x;
    cin >> k >> x;
    for(int i=0; i<k; i++)x*=2;
    cout << x << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}