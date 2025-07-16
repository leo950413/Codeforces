#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    long long s = 0;
    for(int i=0; i<v.size(); i++){
        if(s < v[i] && v[i] != s + 1){
            cout << s + 1 << "\n";
            return 0;
        }
        else{
            s += v[i];
        }
    }
    cout << s + 1 << "\n";
}