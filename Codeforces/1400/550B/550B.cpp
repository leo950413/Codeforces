#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    int n,l,r,x;
    cin >> n >> l >> r >> x;
    int ans = 0;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int bit_mx = pow(2 , n);
    for(int i=2; i< bit_mx; i++){
        if(__builtin_popcount(i) > 1){
            int temp = i;
            int mm = 1e9 , mx = -1e8 , s = 0;
            for(int j=0; j<n; j++){
                bool choose = temp & 1;
                if(choose){
                    if(v[j] > mx){
                        mx = v[j];
                    }
                    if(v[j] < mm){
                        mm = v[j];
                    }
                    s += v[j];
                }
                temp >>= 1;
            }
            // cout << mm << " " << mx << " " << s << "\n";
            if(mx - mm >= x && s >= l && s <= r){
                ans ++;
            }
        }
    }
    cout << ans << "\n";

}