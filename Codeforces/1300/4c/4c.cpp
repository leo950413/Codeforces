#include<iostream>
#include<map>
using namespace std;


int main(){
    map<string ,int>m;
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(!m[s]){
            cout << "OK\n";
            m[s]++;
        }
        else{
            cout << s << m[s]<<"\n";
            m[s]++;
        }
    }
}