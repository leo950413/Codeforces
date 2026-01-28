#include<iostream>
#include<vector>
#include<numeric>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int>v(n + 1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    long long sum = accumulate(v.begin(), v.end(), 0LL);
    if(sum %3LL != 0){
        cout <<  "0\n";
        return 0;
    }
    long long num_2s = 0, s = 0, ans = 0; 
    for(int i=1; i<=n-1; i++){
        s += v[i];
        if(s == (sum/3LL) * 2LL){// if prefix=2s then guarantee the rest sum is 's'
            ans += num_2s;
        }
        if(s == (sum/3LL)){
            num_2s ++;
        }
    }
    cout <<  ans  << "\n";
}