#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
 
map<int , int>m;
void solve(){
    int n , k;
    cin >> n >> k;
    m.clear();
    
    if(k == 0){
        vector<int>a(n),b(n);
        for(int i=0; i<n; i++)cin >> a[i];
        for(int i=0; i<n; i++)cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i=0; i<n; i++){
            if(a[i] != b[i]){
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        m[temp % k]++;
    }
    
    bool end = 0;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        if(m[temp % k] == 0 && m[k - (temp % k)] == 0){
            end |= 1;
        }
        else{
            if(m[temp % k]){
                m[temp%k]--;
            }
            else{
                m[k-(temp)%k]--;
            }
        }
    }
    if(end){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    
    return;
    // m.clear();
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}