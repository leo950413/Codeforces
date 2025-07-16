#include<iostream>
#include <bitset>

using namespace std;

int main(){
    long long n;
    cin >> n;

    for(int i=0; i<=n/1234567; i++){
        for(int j=0; j<=(n-i*1234567)/123456; j++){
            if((n - i * 1234567 - j * 123456) % 1234 == 0){
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}