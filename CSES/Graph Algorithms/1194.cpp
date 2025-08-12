#include<vector>
#include<iostream>
#include<queue>
#include<limits.h>
#include<algorithm>
using namespace std;
vector<string>maze;
vector<vector<int>> dist_monster, dist_person;
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<vector<int>> direction;
int best_dist  = INT_MAX , bound_i , bound_j;
int n , m;
void bfs(queue<pair<int ,int>>&q, vector<vector<int>>&dist){
    while(q.size()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + d[i].first;
            int ny = y + d[i].second;
            if(nx >= 0 && nx < n &&  ny >= 0 && ny < m){
                if(maze[nx][ny] != '#' && dist[nx][ny] == INT_MAX){
                    dist[nx][ny] = dist[x][y] + 1;
                    direction[nx][ny] = i;
                    q.push({nx, ny});
                }
            }
        }
    }
}
void check_valid(int i , int j){
    if (maze[i][j] != '#' && dist_person[i][j] < dist_monster[i][j]){
        if(dist_person[i][j] < best_dist){
            best_dist = dist_person[i][j];
            bound_i = i;
            bound_j = j;
        }
	}
}
int main(){
    cin >> n >> m;
    maze.resize(n);
    dist_monster.resize(n, vector<int>(m, INT_MAX));
	dist_person.resize(n, vector<int>(m, INT_MAX));
	direction.resize(n, vector<int>(m, -1));
    queue<pair<int ,int>>q;
    int start_i , start_j;
    for(int i=0; i<n; i++){
        cin >> maze[i];
        for(int j=0; j<m; j++){
            if(maze[i][j] == 'A'){
                dist_person[i][j] = 0;
                start_i = i;
                start_j = j;
            }
            else if(maze[i][j] == 'M'){
                dist_monster[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    bfs(q, dist_monster);
    q.push({start_i , start_j});
    bfs(q, dist_person);
    for(int i = 0; i < n; i++) {
		check_valid(i, 0);
		check_valid(i, m - 1);
	}
	for (int j = 0; j < m; j++) {
		check_valid(0, j);
		check_valid(n - 1, j);
	}
    if(best_dist == INT_MAX){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << best_dist << "\n";
    string ans , d_str = "RDLU";
    while(bound_i != start_i || bound_j != start_j){
        int ways = direction[bound_i][bound_j];
        ans += d_str[ways];
        bound_i -= d[ways].first;
        bound_j -= d[ways].second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}