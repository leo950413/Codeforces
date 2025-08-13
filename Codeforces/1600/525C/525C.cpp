#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n , prev;
    cin >> n;
    vector<int>v(n+1 ,0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    // for(auto & i : v){
    //     cout << i << " ";
    // }
    bool s = false;
    long long ans = 0;
    for(int i=n-1; i>=1; i--){
        if(v[i+1] - v[i] < 2){
            if(!s){
                prev = v[i];
                s = 1;
            }
            else{
                ans += prev * (v[i] * 1LL);
                s = 0;
            }
            i--;
        }
    }
    cout << ans << "\n";
}