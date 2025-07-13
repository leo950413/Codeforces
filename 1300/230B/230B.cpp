#include<iostream>
#define ll long long
using namespace std;

int bin_sqrt(ll n){
    ll l = 0 , r = 1e6;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(mid * mid > n){
            r = mid - 1;
        }
        else if(mid * mid < n){
            l = mid + 1;

        }
        else{
            return mid;
        }
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    const int MAX = 1000001;
    bool arr[MAX];
    for(int i=0; i<MAX; i++){
        arr[i] = 1;
    }
    arr[1] = 0;
    for(int i=2; i*i<MAX; i++){
        if(arr[i]){
            for(int j=i*i;  j<MAX;j+=i){
                arr[j] = 0;
            }
        }
    }
    while(n--){
        ll t;
        cin >> t;
        int rs = bin_sqrt(t);
        if(rs == -1){
            cout << "NO" << "\n";
        }
        else if(!arr[rs]){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" <<"\n";
        }
    }
}