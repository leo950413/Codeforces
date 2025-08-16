#include<iostream>
#include<vector>

using namespace std;

vector<int>subtree_size;
vector<vector<int>>children;
void dfs(int node){
    subtree_size[node] = 1;
    for(auto &c : children[node]){
        dfs(c);
        subtree_size[node] += subtree_size[c]; // subtree_size - 1 is the actual size
    }
}
int main(){
    int n;
    cin >> n;
    children.resize(n+1);
    subtree_size.resize(n+1);
    for(int i=2; i<=n; i++){
        int t;
        cin  >> t;
        children[t].push_back(i);
    }
    dfs(1);
    for(int i=1; i<=n; i++){
        cout << subtree_size[i]-1 << " ";
    }
}