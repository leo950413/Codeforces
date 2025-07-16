#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin() , v.end());
    int median = v[v.size()/2 ];
    long long s = 0;
    for(auto t:v){
        s += abs(t - median);
    }
    cout << s << "\n";
}