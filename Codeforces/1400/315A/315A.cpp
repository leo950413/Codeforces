#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>a(n , 0) , b(n , 0);
    vector<int>pos(n , 0);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j){
                if(a[i] == b[j]){
                    pos[i] = 1;

                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += !(pos[i]);
    }
    cout << ans << "\n";
    
}