#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        char c;
        cin >> c;
        string s;
        cin >> s;
        s += s;
        int last = -1 ,ans = 0;
        for(int i=s.length() -1; i>=0; i--){
            if(s[i] == 'g')
            {
                last = i;
            }
            else if (s[i] == c && last != -1)
            {
                ans = max(ans , last - i);
            }
            
        }
        cout << ans << "\n";
    }
}