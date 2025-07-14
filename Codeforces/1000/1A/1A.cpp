#include<iostream>

#define ll long long 
using namespace std;
int main(){

    ll n , m , a;
    ll s1 ,s2;
    cin >> n >> m >> a;
    if(n % a == 0){
        s1 = n / a;
    }
    else{
        s1 = n / a + 1;
    }
    if(m % a == 0){
        s2 = m / a;
    }
    else{
        s2 = m / a + 1;
    }
    cout << s1 * s2;
}