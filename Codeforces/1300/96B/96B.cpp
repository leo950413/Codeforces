#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;
vector<ll>irr;
void init(int f , int s , ll n){
    if(n > 1e10){
        return;
    }
    if(f == s){
        irr.push_back(n);
    }
    init(f+1 , s , n*10 + 4);
    init(f , s+1 , n*10 + 7);
}
int main(){
    init(1 , 0 , 4); 
    init(0 , 1 , 7);   
    sort(irr.begin() , irr.end());

    int n;
    cin >> n;
    cout << *lower_bound(irr.begin() , irr.end() , n) << "\n";;
}