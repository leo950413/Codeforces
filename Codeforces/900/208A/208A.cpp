#include<iostream>
#include<string>
#include <sstream>

using namespace std;

int main(){
    string s, res;
    cin >> s;
    size_t pos = 0;
    while((pos = s.find("WUB")) != string::npos){
        s.replace(pos , 3 , " ");
    }
    istringstream iss(s);
    string word;
    while(iss>>word){
        res += word;
        res += " ";
    }
    cout << res << "\n";
}