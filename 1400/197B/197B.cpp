#include<iostream>
#include<vector>
using namespace std;
int gcd(int a, int b){
    a = abs(a);
    b = abs(b);
    if(b > a){
        swap(a , b);
    }
    // cout << a<< " " << b << "\n";
    if(b == 0){
        return a;
    }
    if(b == 1){
        return 1;
    }
    return gcd(a - (a/b) * b , b);

}
int main(){
    int n , m;
    cin >> n >> m;
    if(n < m){
        cout << "0/1\n";
    }
    else{
        int t;
        int a_0 , b_0;
        cin >> a_0;
        for(int i=1; i<=n; i++){
            cin >> t;
        }
        cin >> b_0;
        if(a_0 * b_0 < 0)cout <<"-";
        if(n > m){
                cout << "Infinity\n";
                return 0;
        }
        cout << (abs(a_0) / gcd(a_0 , b_0)) << "/" << (abs(b_0) / gcd(a_0 , b_0));
    }
}