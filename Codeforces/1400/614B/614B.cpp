#include<string>
#include<iostream>
using namespace std;
bool check(string s){
    int one_count = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] != '1' && s[i] != '0'){
            return 0;
        }
        if(s[i] == '1'){
            one_count ++;
        }
    }
    if(one_count > 1){
        return 0;
    }
    return 1;
}
int main(){
    int n;
    cin >> n;
    string temp;
    int zero_times = 0;
    while(n--){
        string s;
        cin >> s;
        if(s[0] == '0'){
            cout << 0 << "\n";
            return 0;
        }
        if(check(s)){
            zero_times += s.length() - 1;
        }
        else{
            temp = s;
        }
    }
    if(temp.empty())cout<<"1";
    else cout << temp;
    while(zero_times){
        cout << "0";
        zero_times--;
    }
}