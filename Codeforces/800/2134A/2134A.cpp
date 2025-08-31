#include<iostream>
#include<vector>
using namespace std;

void print(bool c){
    if(c)cout << "YES\n";
    else cout << "NO\n";
}
void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    if(a <= b){
        print((n%2)==(b%2));
    }
    else{
        print(((n%2)==(b%2)) && ((n%2) == (a%2)));
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}