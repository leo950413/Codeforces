#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        if((n/2)%2){
            cout << 1 + (n/2 - 1)/2 << "\n";
        }
        else{
            cout << n / 4 << "\n";
        }
    }
}