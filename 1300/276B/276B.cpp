#include<iostream>
#include<vector>
#include<map>

using namespace std;
int main(){
    string s;
    cin >> s;
    map<char , int>occur;
    for (char c : s) {
        occur[c]++;
    }
    int odd_num_char = 0;
    for(auto p : occur){
        if(p.second % 2){
            odd_num_char += 1;
        }
    }
    cout << (((odd_num_char - 1) % 2 == 0 || odd_num_char == 0) ? "First" : "Second") << "\n";
    
}