#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main(){
    ll n,x1,x2,y1,y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<pair<ll , ll>>dis;
    for(int i=0; i<n; i++){
        ll xi, yi;
        cin >> xi >> yi;
        ll r1 = (xi - x1)*(xi - x1) + (yi - y1)*(yi - y1);
        ll r2 = (xi - x2)*(xi - x2) + (yi - y2)*(yi - y2);
        dis.push_back(make_pair(r1 , r2));
    }
    dis.push_back({0 , 0});
    ll res = 1e18;
    for(int i=0; i<dis.size(); i++){
        ll r1 = dis[i].first;
        ll r2 = 0;
        for(int j=0; j<dis.size(); j++){
            if(dis[j].first > r1){
                r2 = max(r2 , dis[j].second);
            }
        }
        res = min(res, r1+r2);
    }
    cout << res << "\n";
}