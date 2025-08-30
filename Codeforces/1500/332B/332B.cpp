#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n,k;
    cin >> n >> k;
    vector<long long>v(n+1),pre(n+1, 0),seg(n+1, 0);
    for(int i=1; i<=n; i++)cin >> v[i];
    for(int i=1; i<=k; i++)pre[1] += v[i];// fill the first
    for(int i=2; i<=n-k+1; i++)pre[i] = pre[i-1] - v[i-1] + v[i+k-1];
    long long mx = 0;
    int l_idx = 0; // current maximum left index
    int best_l, best_r;
    for(int i=1; i<=n-2*k+1; i++){
        if(pre[i] > pre[l_idx]){
            l_idx = i;
        }
        if(pre[l_idx] + pre[i + k] > mx){
            mx = pre[l_idx] + pre[i + k]; // i >= idx
            best_l = l_idx;
            best_r = i + k;
        }
    }
    cout << best_l << " " << best_r << "\n";
}