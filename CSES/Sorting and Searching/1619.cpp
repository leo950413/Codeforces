#include<vector>
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int ,int>>t;
    for(int i=0; i<n; i++){
        int start,end;
        cin >> start >> end;
        t.push_back(make_pair(start, 1));
        t.push_back(make_pair(end, -1));
    }
    sort(t.begin(), t.end());
    int cur = 0, mx = 0;
    for(const auto &p : t){
        cur += p.second;
        mx = max(mx , cur);
    }
    cout << mx << "\n";
}