#include<iostream>
using namespace std;;

int main(){
    long long n,a,b,c,ans = 0;
    cin >> n >> a >> b >> c;
    if(b-c >= a){
        ans = n/a;
    }
    else{
        ans = (n-b)/(b-c)+ 1;
        if(n<b){ // not enough for b
            ans = 0;
        }
        ans += (n-ans*b + ans*c)/a;
    }
    cout << ans <<"\n";
}