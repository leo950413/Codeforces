#include<iostream>
long long MOD= 1e9 + 7;
using namespace std;
long long m(long long n){
    return (n%MOD + MOD) % MOD;
}
int main() {
    long long n;
    long long x, y;
    cin >> x >> y >> n;
    switch (n%6ll)
    {
    case 1:
        cout << m(x) << "\n";
        break;
    case 2:
        cout << m(y) << "\n";
        break;
    case 3:
        cout << m(y-x) << "\n";
        break;

    case 4:
        cout << m(-1 *x) << "\n";
                break;

    
    case 5:
        cout << m(-1 *y) << "\n";
                break;

    
    case 0:
        cout << m(x-y) << "\n";
                break;

    default:
        break;
    }
}
