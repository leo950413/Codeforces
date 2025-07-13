#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin >> s;
    string temp(1, s[0]);
    string s2 , s3;
    int w_cnt = 1;
    for(int i=1; i<s.size(); i++){
        if(temp[0] == s[i]){
            w_cnt ++;
        }
        else{
            s2 += string(w_cnt > 2 ? 2 : w_cnt , temp[0]);
            temp = s[i];
            w_cnt = 1;
        }
    }
    s2 += string(w_cnt > 2 ? 2 : w_cnt , temp[0]);
    int idx = 0, cnt = 0 , prev = 0;
    while(idx < s2.length()){
        char c = s2[idx];
        while(s2[idx] == c && idx < s2.length()){
            idx++;
            cnt++;
        }
        if(prev && cnt == 2){
            s3 += string(1, c);
            prev = 0;
        }
        else if(cnt == 2){
            s3 += string(2, c);
            prev = 1;
        }
        else{
            s3 += string(1, c);
            prev = 0;
        }
        cnt = 0;
    }
    cout << s3 << "\n";
}