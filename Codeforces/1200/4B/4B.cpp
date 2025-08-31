#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int d, sumtime;
    cin >> d >> sumtime;
    int t = sumtime;
    vector<pair<int ,int>>v(d+1);
    int mm = 0, mx = 0;
    for(int i=1; i<=d; i++){
        int a,b;
        cin >> a >> b;
        mm += a;
        mx += b;
        v[i] = {b, a};
        t -= a;
    }
    if(mm > sumtime || mx < sumtime){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i=1; i<=d; i++){
        if(!t){
            cout << v[i].second << " ";
            continue;
        }
        // cout << v[i].first << " " << v[i].second << "\n";
        cout << min(v[i].second + t , v[i].first) << " ";
        t -= min(v[i].second + t , v[i].first) - v[i].second;
    }
}