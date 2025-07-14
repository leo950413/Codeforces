#include<iostream>
#include<utility>
#include<limits.h> 
#include <tuple>

int const M = 10000;
int dp2[1001][1001];
int dp5[1001][1001];

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
void init(){
    for(int i=0; i<1001;i++){
        dp2[i][0] = M;
        dp5[i][0] = M;
    }
    for(int i=0; i<1001;i++){
        dp2[0][i] = M;
        dp5[0][i] = M;
    }
}
void print(int n){
    cout << "dp2" << "\n";
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n; j++){
            cout << dp2[i][j] << " "; 
        }
        cout << "\n";
    }
    cout << "dp5" << "\n";
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n; j++){
            cout << dp5[i][j] << " "; 
        }
        cout << "\n";
    }
}
int main(){
    init();
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int t;
            cin >> t;
            std::tie(dp2[i][j], dp5[i][j]) = cnt(t);
        }
    }
    print(n);
    for(int i=2; i<=n; i++){
        for(int j=2; j<=n; j++){
            dp2[i][j] = min(dp2[i-1][j] , dp2[i][j-1]);
            dp5[i][j] = min(dp5[i-1][j] , dp5[i][j-1]);
        }
    }
    print(n);    
}