#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int trailing_zero(string s){
    int cnt = 0;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] != '0')return cnt;
        cnt++;
    }
}

void solve(){
    int n,m;
    cin >>n >>m;
    vector<string>v(n);
    vector<int>t(n);
    int ans = 0;
    for(int i=0; i<n; i++)cin >> v[i];
    for(int i=0; i<n; i++){
        ans += v[i].size() - trailing_zero(v[i]);
        t[i] = trailing_zero(v[i]);
    }
    sort(t.begin(), t.end(),  greater<int>());

    for(int i=1; i<n; i+=2){
        ans += t[i]; // greedy
    }
    if(ans - 1 >= m){
        cout << "Sasha\n";
    }
    else{
        cout << "Anna\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}