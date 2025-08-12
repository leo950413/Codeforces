#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>>adj(n+1);
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b , c}); // undirected graph
    }
    vector<long long>dis(n+1 , 1e18);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0 , 1}); // need to swap dis and node due to priority queue
    dis[1] = 0;
    while(pq.size()){
        long long distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(distance > dis[node])continue;
        for(auto &edge : adj[node]){
            int child = edge.first;
            int w = edge.second;
            if(dis[child] > dis[node] + w){
                dis[child] = dis[node] + w;
                pq.push({dis[child] , child});
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << dis[i] << " ";
    }
}