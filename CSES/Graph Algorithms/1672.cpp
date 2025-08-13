#include<vector>
#include<iostream>
using namespace std;

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<long long>>dist(n+1 , vector<long long>(n+1 , 1e18));
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        if(c < dist[a][b]){
            dist[a][b] = c;
            dist[b][a] = c;
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            if (i == k) continue;
            for (int j = i+1; j <= n; j++){
                if (j == k) continue;
                long long ndist = dist[i][k] + dist[k][j];
                if (dist[i][j] > ndist){
                    dist[i][j] = ndist;
                    dist[j][i] = ndist;
                }
            }
        }
    }
    for(int i=1; i<=q; i++){
        int a,b;
        cin >> a >> b;
        if(a==b)cout << "0\n";
        else if(dist[a][b] == 1e18)cout << "-1\n";
        else cout << dist[a][b] << "\n";
    }
}