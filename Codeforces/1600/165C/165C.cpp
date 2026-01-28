#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    int k;
    string s;
    cin >> k >> s;

    int n = s.length();
    long long ans = 0;
    int prefix = 0;
    vector<int> cnt(n + 1, 0);
    cnt[0] = 1;

    for(int i = 0;i<s.length();i++){
        prefix += (s[i] - '0');
        if(prefix >= k){
            ans += cnt[prefix - k];
        }
        cnt[prefix]++;
    }

    cout << ans << endl;

    return 0;
}