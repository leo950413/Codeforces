#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<map>

using namespace std;

vector<pair<int,int>> directions = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int main(){
    map<char, int>mp;
    int n, m;
    char c;
    cin >> n >> m >> c;
    vector<vector<char>>v(n , vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == c){
                for(auto d : directions){
                    int ni = i + d.first;
                    int nj = j + d.second;
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m){
                        mp[v[ni][nj]]++;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(pair<char, int> p : mp){
        if(p.first == c || p.first == '.'){
            continue;
        }
        ans++;
    }
    cout << ans << "\n";
}