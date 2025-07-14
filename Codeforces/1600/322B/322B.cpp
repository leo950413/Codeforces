#include<vector>
#include<iostream>
#include <initializer_list>

#define ll long long
using namespace std;

int main(){
    ll ans = 0;
    ll  r, b ,g;
    cin >> r >> g >> b;
    if(r==0||g==0||b==0){
        cout << r/3 + g/3 + b/3 << "\n";  
    }else{
        ans = r/3+g/3+b/3;
        r%=3,g%=3,b%=3;
        if(r>=g) swap(r,g);
        if(r>=b) swap(r,b);
        if(g>=b) swap(g,b);
        // r<=g<=b
        if(r==0&&g==2){
            ans+=1;
        }else{
            ans+=r;
        }
        cout << ans << "\n";
    }
}