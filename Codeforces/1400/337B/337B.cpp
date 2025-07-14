#include<iostream>

using namespace std;
int gcd(int a,int b){
    if(a > b ){
        swap(a, b);
    }
    if(a == 1 || b == 1){
        return 1;
    }
    if(a == 0){
        return b;
    }
    gcd(a, b-(b/a)*a);
}
int main(){
    double a, b , c , d;
    cin >> a >> b >> c >> d;
    if(a/b > c/d){
        cout << static_cast<int>((a*d-b*c)/gcd(a*d-b*c , a*d)) << "/" << static_cast<int>(a*d/gcd(a*d-b*c , a*d)) << "\n";
    }
    else if(a/b < c/d){

        cout << static_cast<int>((b*c-a*d)/gcd(b*c-a*d, b*c)) << "/" << static_cast<int>(b*c/gcd(b*c-a*d, b*c)) <<"\n";
    }
    else{
        cout <<  "0/1" << "\n";
    }
}