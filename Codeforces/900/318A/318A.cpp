#include<iostream>
#define ll long long
using namespace std;

int main(){
    ll n , k;
    cin >> n >> k;
    if(n&1){ // if n is odd
        if(k <= n / 2 + 1){
            cout << 2 * k - 1 << "\n";
        }
        else{
            cout << (k - (n / 2) - 1) *2 << "\n";
        }

    }
    else{ // n is even
        if(k <= n / 2){
            cout << 2*k - 1 << "\n";
        }
        else{
            cout << 2 * (k - n/2) << "\n";
        }

    }
} 