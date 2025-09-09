#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int x, w , h;
    bool operator<(node &n2) const{
        if (w == n2.w) return h < n2.h; 
        return w < n2.w;
    }
};
int main(){
    int n,w,h;
    cin >> n >> w >> h;
    vector<node>v;
    for(int i=1; i<=n; i++){
        int t1,t2;
        cin >> t1 >> t2;
        if(t1 > w && t2 > h){
            node t;
            t.x = i;
            t.w = t1;
            t.h = t2;
            v.push_back(t);
        }
    }
    if(v.empty()){
        cout << "0\n";
        return 0;
    }
    sort(v.begin(), v.end());
    int max_len = 0;
    vector<int>dp(v.size() , 1);
    vector<int>prev(v.size() , -1);
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<i; j++){
            if(v[j].w < v[i].w && v[j].h < v[i].h){
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
    }

    int mx = -1, idx = 0;
    for(int i=0; i<dp.size(); i++){
        if(mx < dp[i]){
            idx = i;
            mx = dp[i];
        }
    }
    cout << mx << "\n";
    if (mx == 0) return 0;
    vector<int>ans;
    while(true){
        ans.push_back(v[idx].x);
        idx = prev[idx];
        if(idx == -1){
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans)cout << i << " ";
}