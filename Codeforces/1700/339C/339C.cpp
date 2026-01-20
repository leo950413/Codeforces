#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

short dp[1001][11][11];
int ans[1001];
int main(){
    string s;
    int n;
    cin >> s >> n;
    vector<int>v;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '1')v.push_back(i + 1);
    }
    int cnt = 0;
    for(int p : v) {
        dp[1][p][p] = -1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=10; j++){
            for(auto p : v){
                if(dp[i][j][p]){
                    for(auto p2 : v){
                        if(p == p2)continue; // if next element = last element
                        if(p2 <= j)continue; // if next element <= the gap between left and right
                        dp[i + 1][p2 - j][p2] = p;
                    }
                }
            }
        }
    }
    int flag = 0;
    int start_i, start_p;
    for(int i=1; i<=10; i++){
        for(auto p : v){
            if(dp[n][i][p]){
                flag = 1;
                start_i = i;
                start_p = p;
            }
        }
    }
    if(!flag){
        cout << "NO\n";
        return 0;
    }
    for(int i=n; i>=1; i--){
        ans[i] = start_p;
        int p = dp[i][start_i][start_p];
        start_i = start_p - start_i;
        start_p = p;
    }

    cout << "YES\n";
    for(int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
}