#include<iostream>
#include<utility>
#include<limits.h> 
#include <tuple>
#include<string>
#include<algorithm>

int const M = 10000;
int cnt2[1001][1001];
int cnt5[1001][1001];
int dp2[1001][1001] = {0};
int dp5[1001][1001] = {0};
int dp2_path[1001][1001] , dp5_path[1001][1001];
int v[1001][1001];
using namespace std;
pair<int,int> cnt(int n){
    if(n==0){
        return make_pair(1, 1);
    }
    int t=n;
    int cnt5=0, cnt2=0;
    while(!(t%5)){
        t/=5;
        cnt5++;
    }
    while(!(n%2)){
        n/=2;
        cnt2++;
    }
    return make_pair(cnt2 ,cnt5);
}

// void print(int n){
//     cout << "cnt2" << "\n";
//     for(int i=1; i<=n;i++){
//         for(int j=1; j<=n; j++){
//             cout << cnt2[i][j] << " "; 
//         }
//         cout << "\n";
//     }
//     cout << "cnt5" << "\n";
//     for(int i=1; i<=n;i++){
//         for(int j=1; j<=n; j++){
//             cout << cnt5[i][j] << " "; 
//         }
//         cout << "\n";
//     }
//     cout << "dp2" << "\n";
//     for(int i=1; i<=n;i++){
//         for(int j=1; j<=n; j++){
//             cout << dp2[i][j] << " "; 
//         }
//         cout << "\n";
//     }
//     cout << "dp5" << "\n";
//     for(int i=1; i<=n;i++){
//         for(int j=1; j<=n; j++){
//             cout << dp5[i][j] << " "; 
//         }
//         cout << "\n";
//     }
//     cout << "dp2_path" << "\n";
//     for(int i=1; i<=n;i++){
//         for(int j=1; j<=n; j++){
//             cout << dp2_path[i][j] << " "; 
//         }
//         cout << "\n";
//     }
//     cout << "dp5_path" << "\n";
//     for(int i=1; i<=n;i++){
//         for(int j=1; j<=n; j++){
//             cout << dp5_path[i][j] << " "; 
//         }
//         cout << "\n";
//     }
// }
int main(){
    int n , s=0 , idx_i , idx_j;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> v[i][j];
            if(v[i][j] == 0){
                s = 1;
                idx_i = i;
                idx_j = j;
            }
            std::tie(cnt2[i][j], cnt5[i][j]) = cnt(v[i][j]);
        }
    }
    // print(n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j == 1){
                dp2[i][j] = dp2[i-1][j] + cnt2[i][j];
                dp5[i][j] = dp5[i-1][j] + cnt5[i][j];
                dp2_path[i][j] = 1;
                dp5_path[i][j] = 1;
            }
            else if(i == 1){
                dp2[i][j] = dp2[i][j-1] + cnt2[i][j];
                dp5[i][j] = dp5[i][j-1] + cnt5[i][j];
                dp2_path[i][j] = 2;
                dp5_path[i][j] = 2;
            }
            else{ // 1 for up,down 2 for left,right
                if(dp2[i][j-1] > dp2[i-1][j]){ 
                    dp2[i][j] = dp2[i-1][j] + cnt2[i][j]; 
                    dp2_path[i][j] = 1;
                }
                else{
                    dp2[i][j] = dp2[i][j-1] + cnt2[i][j];
                    dp2_path[i][j] = 2;
                }
                if(dp5[i][j-1] > dp5[i-1][j]){
                    dp5[i][j] = dp5[i-1][j] + cnt5[i][j]; 
                    dp5_path[i][j] = 1;
                }
                else{
                    dp5[i][j] = dp5[i][j-1] + cnt5[i][j];
                    dp5_path[i][j] = 2;
                }
            }
        }
    }
    if(s && min(dp2[n][n] , dp5[n][n]) > 1){
        cout << "1\n";
        for(int i=1; i<idx_i; i++)cout<<"D";
        for(int i=1; i<idx_j; i++)cout<<"R";
        for(int i=idx_i; i<n; i++)cout<<"D";
        for(int i=idx_j; i<n; i++)cout<<"R";
    }
    else{
        cout << min(dp2[n][n] , dp5[n][n]) << "\n";
        if(dp2[n][n] > dp5[n][n]){ // if the number of 2 is more than 5 -> just follow 5's path
            string ans;
            int i = n, j = n;
            while(i > 1 || j > 1){
                if(dp5_path[i][j] == 1){
                    ans += "D";
                    i--;
                }
                else{
                    ans += "R";
                    j--;
                }
            }
            reverse(ans.begin() , ans.end());
            cout << ans << "\n";
        }
        else{
            string ans;
            int i = n, j = n;
            while(i > 1 || j > 1){
                if(dp2_path[i][j] == 1){
                    ans += "D";
                    i--;
                }
                else{
                    ans += "R";
                    j--;
                }
            }
            reverse(ans.begin() , ans.end());
            cout << ans << "\n";
        }
    }
}