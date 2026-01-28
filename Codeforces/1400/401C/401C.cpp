#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

void solve(){
}
int main(){
    int n, m;
    cin >> n >> m;
    string result;
    while(n > 0 && m > 0){
        if(m > n){
            result += "110";
            m -= 2;
            n -= 1;
        } 
        else if (m == n){
            result += "10";
            m -= 1;
            n -= 1;
        } 
        else{

            result += "01";
            m -= 1;
            n -= 1;
        }
    }
    // cout << result << "\n";
    if(((m >= 2 && result.back() == '1') || m >= 3)|| ((n >= 1 && result.back() == '0') || n >= 2)){
        cout << "-1\n";
        return 0;
    }
    if(n){
        result += string(n , '0');
    }
    if(m){
        result += string(m , '1');
    }
    cout << result;
}