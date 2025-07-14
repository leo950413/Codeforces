#include<iostream>
#include <string>
#define ll long long
using namespace std;

int main(){
    string s1,s2,c, n_s1 , n_s2 , nc;
    ll i1, i2 , ic;
    cin >> i1 >> i2;
    ic = i1 + i2;
    s1 = to_string(i1);
    s2 = to_string(i2);
    c = to_string(ic);
    for(int i=0; i<s1.length(); i++){
        if(s1[i] != '0'){
            n_s1 += s1[i];
        }
    }
    for(int i=0; i<s2.length(); i++){
        if(s2[i] != '0'){
            n_s2 += s2[i];
        }
    }
    for(int i=0; i<c.length(); i++){
        if(c[i] != '0'){
            nc += c[i];
        }
    }
    if(stoi(nc) == stoi(n_s1) + stoi(n_s2)){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
}