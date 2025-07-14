#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

vector<ll>arr;

void init(string s){
    arr.push_back(stoll(s));
    if(s.length() == 10){
        return;
    }
    init(s + "4");
    init(s + "7");
}
int main(){
    init("4");
    init("7");
    ll l,r;
    cin >> l >> r;
    int i, j , prev_j = 0;
    ll ans = 0;
    sort(arr.begin() , arr.end());
    // for(int i=0; i<arr.size(); i++){
    //     cout  << arr[i] <<"\n";
    // }
    for(ll i=l; i<=r; i++){
        int j;
        for(j=prev_j; j<arr.size(); j++){
            if(arr[j] >= i){
                break;
            }
        }
        ans += arr[j];
        prev_j = j;
    }
    cout << ans << "\n";
}