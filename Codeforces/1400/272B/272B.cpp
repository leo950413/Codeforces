#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int>v(t), cnt(30, 0);
    for(int i=0; i<t; i++)cin >> v[i];
    for(int i=0; i<t; i++)cnt[__builtin_popcountll(v[i])]++;
    long long ans = 0;
    for(int i=0; i<30; i++){
        ans += 1LL * cnt[i] * (cnt[i] - 1)/2;
    }
    cout << ans  << "\n";
}