#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int ,int>p1, pair<int, int>p2){
    return p1.second < p2.second;
}
int main(){
    long long n,r,avg,ans=0;
    cin >> n >> r >> avg;
    long long require = n * avg;
    vector<pair<int, int>>v;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a , b});
        require -= a;
    }

    if(require <= 0){
        cout << "0\n";
        return 0;
    }

    sort(v.begin(), v.end() , comp);
    for(auto k: v){
        if(k.first < r && require > 0){
            ans += min(require , r - k.first) * k.second;
            require -= r - k.first;
        }
    }
    cout << ans;
}