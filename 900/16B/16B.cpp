#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
    vector<pair <ll , ll>> p; 
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m;i++){
        int a, b;
        cin >> a >> b;
        p.push_back(make_pair(a, b));
    }
    sort(p.begin(), p.end(),
          [](auto a, auto b) {
              return a.second < b.second;
          });
    ll sum = 0;
    while(true){      
        if(p.empty())break;      
        pair<ll ,ll> m = p.back();
        if(n < m.first){
            sum += m.second * n;
            break;
        }
        else{
            n -= m.first;
            sum += m.second * m.first;
        }
        p.pop_back();
    }
    cout << sum << "\n";
}