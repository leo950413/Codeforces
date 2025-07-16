#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    char prev = s[0];
    int t = 1 , ans = 0;
    for(size_t i=1; i<s.length(); i++){
        if(prev == s[i]){
            t++;
        }
        else{
            ans = max(ans , t);
            t = 1;
            prev = s[i];
        }
    }
    cout << max(ans, t) << "\n";
}