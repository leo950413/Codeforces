#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int t;
    cin >> t;
    vector<int>a(t+1),  pre(t+1) , suff(t+1);
    vector<int>ans(t+1);
    pre[0] = 1e7;
    for(int i=1; i<=t; i++){
        cin >> a[i];
        if(a[i] < pre[i-1]){
            pre[i] = a[i];
        }
        else{
            pre[i] = pre[i-1];
        }
    }
    suff[t] = a[t];
    for(int i=t; i>0; i--){
        if(a[i-1] > suff[i]){
            suff[i -1] = a[i - 1];
        }
        else{
            suff[i - 1] = suff[i];
        }
    }
    for(int i=1; i<=t; i++){
        if(a[i] == pre[i]){
            ans[i] = 1;
        }
    }
    for(int i=1; i<=t; i++){
        if(a[i] == suff[i]){
            ans[i] = 1;
        }
    }
    for(int i=1; i<=t; i++){
        cout << ans[i];
    }
    cout << "\n";
}
int main(){
    int n;
    cin >> n;
    while(n--)solve();
}