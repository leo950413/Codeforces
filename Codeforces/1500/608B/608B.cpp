#include<iostream>
#include<vector>
using namespace std;


int main(){
    string s1, s2;
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    int n = s1.size() - 1, m = s2.size() - 1;
    vector<int> pre0(m+1, 0), pre1(m+1, 0);
    for(int i=1; i<=m; i++) {
        pre0[i] = pre0[i-1] + (s2[i] == '0');
        pre1[i] = pre1[i-1] + (s2[i] == '1');
    }
    long long ans = 0;
    for(int i=1; i<=n; i++){
        if(s1[i] == '0'){
            ans += pre1[m - n + i] - pre1[i-1];
        }
        else{
            ans += pre0[m - n + i] - pre0[i-1];
        }
    }
    cout<< ans << "\n";
}