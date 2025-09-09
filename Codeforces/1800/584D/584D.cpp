#include<iostream>
#include<vector>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    if(isPrime(n)){
        cout << 1 << "\n" << n << "\n";
    }
    else{
        cout << 3 << "\n";
        n-=3;
        for(int i=2; i<=n; i++){
            if(isPrime(n-i) && isPrime(i)){// 3 + n-i + i
                cout << 3 << " " << i << " " << n- i;
                break; 
            }
        }
    }
}