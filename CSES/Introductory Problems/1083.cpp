#include<iostream>
using namespace std;

int main(){
    long  long sum = 0;
    long long  n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int temp;
        cin >> temp;
        sum += temp;
    }
    cout << (1+n)*n/2 - sum << "\n";
}