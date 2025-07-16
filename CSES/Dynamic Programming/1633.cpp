#include<iostream>
using namespace std;
const int MX = 1e6;
const int MOD = 1e9 + 7;
int arr[MX] = {0};

int main(){
    int n;
    cin >> n;
    arr[0] = 1;
    for(int i=1; i<=n; i++){
        
        for(int j=1; j<=min(6, i); j++){
            arr[i] += arr[i-j];
            arr[i] %= MOD;
        }
        // cout << arr[i] << " ";
    }
    cout << arr[n] << "\n";
}