#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
vector<ll>a,b;

bool valid(int i ,int mid){
    // target = a[i-1]
    return b[mid]-a[i] >= a[i-1];
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, m, ans=1;
        cin >> n >> m;
        while(n--){
            ll temp;
            cin >> temp;
            a.push_back(temp);
        }
        while(m--){
            ll temp;
            cin >> temp;
            b.push_back(temp);
        }
        sort(b.begin() , b.end());
        a[0] = min(a[0] , b.front() - a[0]);
        for(int i=1; i<a.size(); i++){
            int l = 0, r = b.size()-1;
            while(l <= r){
                ll mid =  l + (r - l) / 2;
                if(valid(i , mid)){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            // int l = lower_bound(b.begin() , b.end() , a[i] + a[i-1]) - b.begin();
            // cout << l << "\n";
            if(a[i-1] > max(a[i] , b.back()-a[i])){
                ans = 0;
                break;
            }
            if(l >= b.size()){
                continue;
            }
            else if(a[i] < a[i-1]){
                a[i] = b[l]-a[i];
            }
            else
            {
                a[i] = min(b[l]-a[i] , a[i]);
            }
            // cout << "i = " << i << "a[i] = " << a[i] << "\n";
        }
        cout << (ans ? "YES": "NO" )<<"\n";
        a.clear();
        b.clear();
    }
}
