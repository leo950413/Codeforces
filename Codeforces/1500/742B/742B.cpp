#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    long long ans = 0;
    int n,x;
    cin >> n>>x;
    unordered_map<int ,int>um;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        ans += um[temp^x];
        um[temp]++;
    }
    cout << ans <<"\n";
}