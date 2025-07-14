#include <iostream>
#include <string>
using namespace std;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int i=0, j=0;
    int s1_con_num = 0 , s2_con_num = 0;
    char prev ='\0';
    if (s2.length() < s1.length() || s2.length() > 2 * s1.length() || s2[0] != s1[0]) {
        cout << "NO\n";
        return;
    }
    while(true){
        if(prev == '\0'){
            if(i == s1.size()){
                break;
            }
            prev = s1[i];
        }
        while(prev == s1[i]){s1_con_num++;i++;}
        while(prev == s2[j]){s2_con_num++;j++;}

        if(s1_con_num * 2 < s2_con_num || s1_con_num > s2_con_num){
            cout <<  "No" <<"\n";
            return;
        }
        else{
            s1_con_num = 0;
            s2_con_num = 0;
            prev = '\0';
        }
    }    
    if (j != s2.size()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
