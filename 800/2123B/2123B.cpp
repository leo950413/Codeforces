#include<iostream>
#include<vector>
using namespace std;
void solve(){   
    int n , j, k , m = -10000;
    cin >> n >> j >> k;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] > m){
            m = a[i];
        }
    }
    if(k == 1){
        if(a[j - 1] == m){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO\n";
        }
    }
    else{
        cout << "YES" << "\n";
    }
}
int main(){
    int n;
    cin>>n;
    while(n--)solve();
}