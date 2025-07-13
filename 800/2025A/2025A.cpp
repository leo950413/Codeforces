#include<iostream>
#include <cstring>

using namespace std;

int main(){
    int j;
    cin >> j;
    while(j--){
        int is_same = 0, len=0;
        string s, t;
        cin >> s >> t;
        for(int i=0; i<min(s.length() , t.length()); i++){
            if(s[i] == t[i]){
                len ++;
            }
            else{
                break;
            }
        }
        cout << s.length() + t.length() + 1 - max(len , 1) << endl; 
    }
    
}