#include<iostream>
#include <cmath> 
#include<vector>
#include<algorithm>
using namespace std;
void s(){
    int n,x;cin>>n>>x;
    int bits=__builtin_popcountll(x);
    if (n<=bits){
        cout<<x;
        return;
    }
    if((n-bits)%2==0){
        cout<<x+n-bits;
        return;
    }
    else{
        if (x>1){
            cout<<x+n-bits+1;
            return;
        }
        if (x==1){
            cout<<n+3;
            return;
        }
        else{
            if (n==1){
                cout<<-1;return;
            }
            else{
                cout<<n+3;return;
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
            s();
            cout << "\n";
    }
}