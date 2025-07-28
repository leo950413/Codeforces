#include<iostream>
#include<vector>
#include<queue>
bool v[1005][1005];
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,ans=0;
    cin >> n >> m;
    // vector<vector<char>>v(n, vector<char>(m));
    vector<pair<int ,int>>d = {{-1, 0},{1, 0}, {0, 1}, {0, -1}};
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            if(s[j] == '.'){
                v[i][j] = 1;
            }
            else{
                v[i][j] = 0;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]){
                queue<pair<int , int>>q;
                q.push({i , j});
                v[i][j] = 0;
                while(!q.empty()){
                        // cout << ans<< " " <<i << " " << j <<" " <<q.size() << "\n";
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int k=0; k<4; k++){
                            int nx = x + d[k].first;
                            int ny = y + d[k].second;
                            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                                if(v[nx][ny]){
                                    // cout << nx << " " << ny << "\n";
                                    q.push({nx , ny});
                                    v[nx][ny] = 0;
                                }
                            }
                        }
                    }
                ans++;
            }
        }
    }
    cout << ans << "\n";
}