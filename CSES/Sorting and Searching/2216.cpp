#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long n ,ans=1;
    cin >> n;
    vector<int>v(n+1);
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v[temp] = i;
    }
    for(int i=1; i<n; i++){
        if(v[i+1] < v[i]){
            ans ++;
        }
    }
    cout << ans << "\n";
}