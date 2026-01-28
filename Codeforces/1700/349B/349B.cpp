#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>ans(n , 0);
    vector<int>cost(10);
    int mn = 1e9, mn_id = -1;
    for(int i=1; i<10; i++){
        cin >> cost[i];
        if(cost[i] < mn){
            mn_id = i;
            mn = cost[i];
        }
    }
    if(mn > n){
        cout << "-1\n";
        return 0;
    }
    int mx_len = n / mn;
    for(int i = 0; i<mx_len; i++){
        ans[i] = mn_id;
    }
    int curr = n - mx_len * mn;
    for(int i=mx_len-1; i>=0; i--){
        curr += cost[ans[i]];
        // cout << curr << " ";
        bool changed = 0;
        for(int j=9; j>=1; j--){
            if(curr >= cost[j]){
                curr -= cost[j];
                ans[i] = j;
                changed = 1;
                break;
            }
        }
        if(!changed){
            curr -= cost[ans[i]];
        }
    }
    for(int i=mx_len-1; i>=0; i--){
        cout << ans[i];
    }
}