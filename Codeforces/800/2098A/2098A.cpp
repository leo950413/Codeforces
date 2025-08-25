#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(){
    vector<int>n;
    for(int i=0; i<10; i++){
        char c;
        cin >> c;
        n.push_back(c - '0');
    }
    sort(n.begin() , n.end());
    for(int i=9; i>=0; i--){
        auto it = lower_bound(n.begin() , n.end(), i);
        cout << *it;
        n.erase(it);
    }
    cout << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
}