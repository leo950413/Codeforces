#include<iostream>
#include<vector>
#include<utility>
#include<numeric>

using namespace std;
int main(){
    int n,k;
    long long s = 0;
    cin >> n >> k;
    vector<long long>vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
        s += vec[n];
    }
    vector<pair<long long ,int>> pre(n , {-1, -1});
    pre[n-k] = {s, n-k};
    for(int i=n-k-1; i>=0; i--){
        s -= vec[i + k];
        s += vec[i];
        pre[i] = max(pre[i+1] , {s , i});
        if(pre[i+1].first == s){
            pre[i].second = i;
        }
    }
    s = accumulate(vec.begin(), vec.end(), 0LL);
    pair<int, int>ans(0, pre[k].second);
    long long ms = s + pre[k].first;
    for(int i=1; i<=n-2*k; i++){
        s -= vec[i - 1];
        s += vec[i + k - 1];
        if(ms < s + pre[i + k].first){
            ans = {i , pre[i + k].second};
            ms = s + pre[i+k].first;
        }
    }
    cout << ans.first + 1 << " " << ans.second + 1 << "\n";

}