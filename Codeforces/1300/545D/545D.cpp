#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end() );
    long long sum = 0;
    int ans = n;
    for(int i=0; i<v.size(); i++){
        if(sum > v[i]){
            ans--;
        }
        else{
            sum += v[i];
        }
    }
    cout << ans<<"\n";
}