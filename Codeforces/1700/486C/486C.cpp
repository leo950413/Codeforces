#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,p;
    string s;
    cin >> n >> p;
    cin >> s;
    s = ' ' + s;
    if(p > n/2)p = n + 1 - p; // move curser to left
    int l ,r, t = 0, ttl = 0;
    for(int i=1; i<=n/2; i++){
        int diff = abs(s[i] - s[n  + 1 - i]);
        if(diff > 0){
            if(!t){
                l = i;
                t = 1;
            }
            ttl += min(diff, 26 - diff);
            r = i;
        }
    }
    if(ttl == 0)cout <<  0;
    else if(l >= p)cout << r - p + ttl; 
    else if(p >= r)cout << p - l + ttl;
    else{
        cout << min(2*(p - l) + r - p, 2*(r - p) + p - l) + ttl; // if cursor is in the middle of two pointer 
    }
}