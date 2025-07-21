#include<iostream>
using namespace std;

int main(){
    // just put it in the middle
    int a,b,r;
    cin >> a >> b >> r;
    if(a >= r*2 && b >= r*2){
        cout << "First\n";
    }
    else{
        cout << "Second\n";
    }
}