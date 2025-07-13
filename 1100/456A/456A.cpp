#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int , int>>p;
    while(n--){
        int a,b;
        cin >> a >> b;
        p.push_back(make_pair(a, b));
    }
    sort( p.begin( ), p.end( ), [ ]( const auto& l, const auto& r )
    {
    return l.first > r.first;
    });
    for(int i=0; i<p.size()-1; i++){
        if(p[i].second < p[i+1].second){
            cout << "Happy Alex" << "\n";
            return 0;
        }
    }
    cout << "Poor Alex" << "\n";
}