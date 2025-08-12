#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>v(24 , vector<int>(60 , 0));

int main(){
    int n, mx = 0;
    cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        v[a][b]++;
        mx = max(v[a][b] ,mx);
    }
    cout << mx << "\n";
}