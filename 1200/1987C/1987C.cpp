#include<iostream>
#include<vector>
#define ll long long 
using namespace std;

void print(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void solve(){
    int n;
    cin >> n;
    vector<int>h;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        h.push_back(temp);
    }
    int ans = h[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        ans = max(ans + 1, h[i]);
    }
    cout << ans << "\n";
}
int main(){
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}
