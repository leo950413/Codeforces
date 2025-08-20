#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int,int> compress;
    vector<int> a(n), b(n), p(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i] >> p[i];
        b[i]++;
        compress[a[i]];
        compress[b[i]];
    }
    int idx = 0;
    for(auto&x : compress){
        x.second = idx;
        idx++;
    }
    vector<vector<pair<int , int>>>project(idx);
    // might be multi 
    for(int i=0; i<n; i++){
        int start_time = compress[a[i]];
        int end_time = compress[b[i]];
        project[end_time].push_back({start_time , p[i]});
    }
    vector<long long>dp(idx , 0);
    for(int i=0; i<idx; i++){
        if(i > 0){
            dp[i] = dp[i-1];
        }
        for(auto p : project[i]){
            dp[i] = max(dp[i] , dp[p.first] + p.second);
        }
    }
    cout << dp[idx-1] << "\n";
}