#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

int main(){
    TxtIO;
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int mn = 1e9;
    for(int i=0; i<n; i++){ // take every v[i] as min(v)
        int mn_ub = upper_bound(v.begin() ,v.end(), v[i] * 2) - v.begin();
        mn = min(mn , n - mn_ub + i);
    }
    cout << mn << "\n";
}