#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long s = 0, mx = 0, all_negative = 1, max_negative = -1000000000;
    for(int i=0; i<n; i++){
        long long temp;
        cin >> temp;
        if(temp > 0){
            all_negative=0;
        }
        else{
            max_negative=max(max_negative , temp);
        }
        s += temp;
        s = max(s, 0ll);
        mx = max(mx , s);
    }
    if(all_negative){cout << max_negative << "\n";return 0;}
    cout << mx << "\n";
}