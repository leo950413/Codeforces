#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(){
    int i;
    cin >> i;
    if(i%4 == 0){
        cout << "Bob" << "\n";
    }
    else{
        cout << "Alice" << "\n";
    }
}
int main(){
    int n;
    cin >> n;
    while(n--)solve();
}