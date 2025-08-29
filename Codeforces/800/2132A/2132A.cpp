#include<iostream>
#include<string>

using namespace std;

void solve(){
    int t;
    cin >> t;
    string s1,s2,s3;
    cin >> s1 >> t >> s2 >> s3;
    for(int i=0; i<t; i++){
        if(s3[i] == 'D'){
            s1 = s1 + s2[i];
        }
        else{
            s1 = s2[i] + s1;
        }
    }
    cout << s1 << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}