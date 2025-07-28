#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int>v(101, 0);
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        for(int j=0; j<t; j++){
            int k;
            cin >> k;
            v[k] = 1;
        }
    }
    for(int i=1; i<=m; i++){
        if(!v[i]){
            cout << "NO\n";
            return 0;
        }
    }
    cout <<"YES\n";
    return 0;
}