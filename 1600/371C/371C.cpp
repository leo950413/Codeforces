#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
ll money;
string s;
vector<int>need(3) , price(3) , have(3);
bool check(ll n){
    ll s = 0;
    for(int i=0; i<3; i++){
        s += max(n*need[i] - have[i], 0ll) * price[i];
    }
    return money >= s;
}
int main(){
    cin >> s;
    need[0] = (count(s.begin() , s.end() , 'B'));
    need[1] = (count(s.begin() , s.end() , 'S'));
    need[2] = (count(s.begin() , s.end() , 'C'));
    for(int i=0; i<3; i++){
        cin >> have[i];
    }
    for(int i=0; i<3; i++){
        cin >> price[i];
    }
    cin >> money;
    int can_make = 1e7;
    for(int i=0; i<3; i++){
        if(need[i] != 0){
            can_make = min(have[i] / need[i] , can_make);
        }
    }
    for(int i=0; i<3; i++){
        have[i] -= can_make*need[i];
    }
    int d=0; // the price of ingredient already had.
    for(int i=0; i<3; i++){
            d += have[i]* price[i];
    }
    int p=0; // the total price of making a burger.
    for(int i=0; i<3; i++){
            p += need[i]*price[i];
    }
    ll l=0 ,r=money+have[0]+have[1]+have[2];
    while(l<=r){
        ll mid = l + (r-l)/2;
        // cout << l << " " <<  r << "\n";
        if(check(mid)){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << can_make + l - 1 << "\n";
}