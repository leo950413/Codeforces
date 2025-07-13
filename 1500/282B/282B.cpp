#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n;
    cin >> n;
    long long a,g,sa = 0,sg = 0;
    string ans;
    for(int i=0; i<n; i++){
        cin >> a >> g;
        if(sa + a > sg + 500){
            sg += g;
            ans += 'G';
        }
        else{
            sa += a;
            ans += 'A';
        }
    }
    
    if(abs(sa - sg) > 500 *1LL){
        cout << "-1\n";
    }
    else{
        cout << ans << "\n";
    }
}