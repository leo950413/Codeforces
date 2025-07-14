#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct DSU{
    vector<int> p , sz;
    DSU(int n):p(n+1) , sz(n+1, 1){
        for(int i=1; i<=n; i++)p[i] = i;
    }
    int find(int x){
        if(p[x] == x){
            return x;
        }
        else{
            return p[x] = find(p[x]);
        }
    }
    void unite(int a , int b){
        a=find(a); b=find(b);
        if(a == b)return;
        if(sz[a] < sz[b]) swap(a, b);
        p[b]=a; sz[a]+=sz[b];
    }

};
int main(){
    int n, m;
    cin >> n >> m;
    if(!m){
        for(int i=1;i<=n;i++){
            cout << i<< " ";
        }
        return 0;
    }
        
    DSU dsu(n);
    vector<vector<int>>group(n+1);
    while(m--){
        int a,b; cin>>a>>b;
        dsu.unite(a,b);
    }
    for(int i=1; i<=n; i++){
        int idx = dsu.find(i);
        group[idx].push_back(i);
        if(group[idx].size() > 3){
            cout << "-1" <<  "\n";
            return 0;
        }
    }
    vector<vector<int>> g1,g2,g3;
    for(auto &v : group){
        if(v.empty()) continue;
        (v.size()==1 ? g1 : v.size()==2 ? g2 : g3).push_back(v);
    }
    if(g2.size() > g1.size() || (g1.size() - g2.size()) %3){
        cout << "-1\n";
        return 0;
    }
    for(auto &v:g3){
        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
    }
    for(size_t i=0;i<g2.size();++i){
        auto team=g2[i];
        team.push_back(g1.back()[0]); g1.pop_back();
        cout<<team[0]<<" "<<team[1]<<" "<<team[2]<<"\n";
    }

    for(size_t i=0;i<g1.size();i+=3){
        cout<<g1[i][0]<<" "<<g1[i+1][0]<<" "<<g1[i+2][0]<<"\n";
    }
}