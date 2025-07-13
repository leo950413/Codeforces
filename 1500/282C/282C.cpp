#include<iostream>
#include<string>
using namespace std;

int main(){
    bool s1_contain_one = 0 , s2_contain_one = 0;
    string s1 , s2;
    cin >> s1;
    if(s1.find('1') !=  string::npos){
        s1_contain_one = 1;
    }
    cin >> s2;
    if(s2.find('1') !=  string::npos){
        s2_contain_one = 1;
    }
    if(s1.length() != s2.length()){
        cout << "NO" << "\n";
    }
    else if(s1_contain_one && s2_contain_one){
        cout << "YES\n"; 
    }
    else if (!s1_contain_one && !s2_contain_one){
        cout << "YES\n";
    }
    else{
        cout << "NO" << "\n";
    }
    
    

}