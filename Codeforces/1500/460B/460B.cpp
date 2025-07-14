#include<iostream>
#include<cmath>
#include<vector>
#define ll long long

ll poww(ll a, ll b)
{
    ll res = 1;
    for(int i = 1; i<=b; ++i)
        res *= a;
 
    return res;
}
using namespace std;

int main(){
    int a,b,c;
    vector<ll>sol;
    cin >> a >> b >> c;
    for(int i=1; i<82; i++){
        ll pos_sol = b*poww(i , a) + c;
        int s=0;
        ll n = pos_sol;
        while(n){
            s += n%10;
            n /= 10;
        }
        if(s == i && pos_sol < 1000000000){
            sol.push_back(pos_sol);
        }
    }
    cout  << sol.size() << "\n";
    for(auto i : sol){
        cout << i << " ";
    }
}