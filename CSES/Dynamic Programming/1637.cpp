#include<iostream>
#include<climits>
#include<string>
using namespace std;
int const SIZE = 1e6 + 1;
int memo[SIZE] = {0};
void init(int n){
    memo[0] = 0;
    for(int i=1; i<=n; i++){
        int t = i;
        int digit = t %10;
        memo[i] = 1e9;
        while(t){
            memo[i] = min(memo[i] , memo[i-digit] + 1);
            t/=10;
            digit = t % 10;
        }
    }
}
// int rec(int n){

//     if(n==0)return 0;
//     if(memo[n]!=-1)return memo[n];

//     string s = to_string(n);
//     int ans = INT_MAX;

//     for(int i=0; i<s.length(); i++){
//         if(s[i] != '0'){
//             ans  = min(ans , rec(n - (s[i] - 48)) + 1);
//         }
//     }

//     memo[n] = ans;
//     return ans;
// }
int main(){
    // for(size_t i=0; i<SIZE; i++)memo[i]=-1;
    int n;
    cin >> n;
    // cout << rec(n) << "\n";
    init(n);
    cout << memo[n] << "\n";
}

