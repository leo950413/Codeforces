#include<iostream>
#include<string>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while(q--){
            int l, r;
            int bad = 2;
            cin >> l >> r;
            l--;
            r--;
            for(int i=0; i<l; i++){
                if(s[i] == s[l]){
                    bad -= 1;
                    break;
                }
            }
            for(int i=r+1; i<n; i++){
                if(s[i] == s[r]){
                    bad -= 1;
                    break;
                }
            }
            if(bad == 2){
                cout << "NO" << "\n";
            }
            else{
                cout <<"YES"<<"\n";
            }
        }
    }
}