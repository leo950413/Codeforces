#include<iostream>
#include<vector>
using namespace std;

int N = 101;
int t = 0;
vector<vector<bool>>adj;
vector<pair<int ,int>>v;
void solve(){
    int mode, a, b;
    cin >> mode >> a >> b;
    if(mode == 1){
        t++;
        int i=1;
        for(auto p : v){
            int c = p.first ,d = p.second;
            if((c < a && a < d) || (c < b && b < d)){
                adj[t][i] = 1;
            }
            if((a < c && c < b) || (a < d && d < b)){
                adj[i][t] = 1;
            }
            i++;
        }
        for(int k = 1; k <= t; k++){
            for(int i = 1; i <= t; i++){
                for(int j = 1; j <= t; j++){
                    if(adj[i][k] && adj[k][j]){
                        adj[i][j] = true;
                    }
                }
            }
        } 
        
        v.push_back({a, b});
    }
    else{
        cout << (adj[a][b] ? "YES\n" : "NO\n");
    }
}
int main(){
    adj.resize(N, vector<bool>(N, 0));
    int q;
    cin >> q;
    while(q--){
        solve();
    }
}