#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<char> mirror_char= {'A' , 'H' , 'I' , 'M' , 'O' ,'T' , 'U' , 'V' , 'W' , 'X' , 'Y'};
int main(){
    string s;
    cin >> s;
    for(auto c : s){
        int isvalid = 0;
        for(auto i : mirror_char){
            if(c == i){
                isvalid = 1;
                break;
            }
        }
        if(!isvalid){
            cout << "NO" << "\n";
            return 0;
        }
    }
    string s2 = s;
    reverse(s.begin(), s.end());
    if(s2 == s){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
}