#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int N = 30;
    vector<double>dp(N , 0);
    int s1_pos=0, s2_pos=0;
    string s1,s2;
    cin >> s1 >> s2;
    s1_pos = count(s1.begin(), s1.end(), '+') - count(s1.begin(), s1.end(), '-');
    s2_pos = count(s2.begin(), s2.end(), '+') - count(s2.begin(), s2.end(), '-');
    int ques = count(s2.begin(), s2.end(), '?');
    if(abs(s1_pos - s2_pos) > ques){
        cout << 0;
        return 0;
    }
    dp[N/2] = 1;
    for(auto c : s2){
        if(c == '?'){
            double next = 0;
            for(int i=0; i<N; i++){
                if(dp[i] == 0){
                    dp[i] += next;
                    next = 0;
                }
                else if(i + 1 <N && i - 1 >= 0){
                    double p =  0.5 * dp[i];
                    dp[i-1] += p;
                    dp[i] = next;
                    next =  p;
                }
                // cout << next << " " << i << "\n";
            }
        }
    }
    cout << setprecision(10) << dp[N/2 + s2_pos - s1_pos];
}