#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        ll n , k ,x, s=0;
        cin >> n>> k >> x;
        ll _n = n;
        vector<int> arr;
        while(_n--){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            s += temp;
        }
        if(s * k < x){ // if not exist such L
            cout << 0 << "\n";
            continue;
        }
        if(x%s == 0){
            cout << (k-(x/s))*n + 1  <<   "\n";
            continue;
        }
        ll pos = n * (k - (x / s));
       
        x -= (x/s) * s;
        ll s2 = 0;
        ll cnt = 0;
        for(int i=n-1; i>=0; i--){
            s2 += arr[i];
            cnt ++;
            if(s2 >= x){
                pos -= cnt - 1;
                break;
            }
        }
        cout << pos << "\n";
    }
    
}