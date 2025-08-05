#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
bool isprime(long long n){
    for(int i=2; i<=round(sqrtl(n)); i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
// https://en.wikipedia.org/wiki/Goldbach%27s_conjecture
int main(){
    long long n;
    cin >> n;
    if(isprime(n)){
        cout << "1\n";
    }
    else if (n%2 == 0) // n is the sum of two prime
    {
        cout  << "2\n";
    }
    else if(isprime(n-2)){
        cout << "2\n";
    }
    else{
        cout << "3\n"; // n = (n-3) + 3 
                       // n-3 is even f(n-3) = 2
    }
    
}