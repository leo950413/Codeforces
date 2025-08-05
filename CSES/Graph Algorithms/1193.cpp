#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int start_i, start_j , end_i , end_j;
    int n, m;
    cin >> n >> m;
    vector<vector<char>>v(n , vector<char>(m));
    vector<vector<bool>>visited(n , vector<bool>(m , 1));
    vector<vector<int>>path(n , vector<int>(m , 0));
    vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    string s = "RDLU";

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
            if(v[i][j] == 'A'){
                start_i = i;
                start_j = j;
            }
            if(v[i][j] == 'B'){
                end_i = i;
                end_j = j;
                v[i][j] = '.';
            }
        }
    }
    queue<pair<int, int>>q;
    q.push({start_i, start_j});
    bool find = 0;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            pair<int , int>p = d[k];
            int ni = i + p.first;
            int nj = j + p.second;
            if(ni < n && ni >= 0){
                if(nj < m && nj >= 0){
                    if(v[ni][nj] == '.' && visited[ni][nj]){
                        q.push({ni, nj});
                        path[ni][nj] = (k+2)%4;
                        visited[ni][nj] = 0;
                    }
                    if(ni == end_i && nj == end_j){
                        find = 1;
                    }
                }
            }
        }
        if(find){
            break;
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         if(path[i][j]<4&& path[i][j] >= 0)cout << s[path[i][j]] << " ";
    //         else cout << "-1 ";
    //     }
    //     cout << "\n";
    // }
    if(!find){
        cout << "NO\n";
    }
    else{
        string ans;
        while(!(end_i == start_i && end_j == start_j)){
            // cout << path[end_i][end_j] << "\n";
            pair<int ,int>direction = d[path[end_i][end_j]];
            ans += s[(path[end_i][end_j]+2)%4];
            end_i += direction.first;
            end_j += direction.second;
        }
        reverse(ans.begin() , ans.end());
        cout <<"YES\n"<< ans.size() << "\n" <<ans << "\n";
    }
    
}