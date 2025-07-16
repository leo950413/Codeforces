#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main(){
    vector<pair<int ,int>>v;
    int n;
    cin >> n;
    while(n--){
        int start,end;
        cin>>start>>end;
        v.push_back(make_pair(end,start));
    }
    sort(v.begin(), v.end());
    int ans=1, end=v[0].first;
    for(int i=1; i<v.size(); i++){
        // cout << end << " " << v[i].second << " " << "\n";
        if(end <= v[i].second){
            ans++;
            end = v[i].first;
        }
    }
    cout << ans << "\n";
}