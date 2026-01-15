#include<vector>
#include<iostream>
#include<queue>

using namespace std;

int n,m,k;
int s_cnt = 0, cnt = 0;// '.' s number
int start_i, start_j;
vector<vector<char>>v;
vector<vector<bool>>preserve;
vector<vector<bool>>visited;
const std::vector<std::pair<int, int>> dir = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0}
};

void bfs(int i , int j){
    if(cnt == s_cnt - k){
        return;
    }
    cnt++;
    preserve[i][j]=1;
    visited[i][j]=1;
    for(int k=0; k<4; k++){
        int ni = i + dir[k].first;
        int nj = j + dir[k].second;
        if(ni >= 0 && ni < n && nj >= 0 && nj < m){
            if(v[ni][nj] == '.' && !visited[ni][nj])bfs(ni, nj);  
        }
    }
}
int main(){
    
    cin >> n >> m >> k;
    v.resize(n, vector<char>(m));
    preserve.resize(n , vector<bool>(m , 0));
    visited.resize(n , vector<bool>(m , 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
            if(v[i][j] == '.'){
                s_cnt++;
                start_i = i;
                start_j = j;
            }
        }
    }
    bfs(start_i, start_j);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!preserve[i][j] && v[i][j] == '.'){
                v[i][j] = 'X';
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << v[i][j];
        }
        cout << "\n";
    }
}