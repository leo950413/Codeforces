#include<iostream>
#include<string>
#include <algorithm>


using namespace std;

string abc_to_rxcy(string a){
    int l = 0, s= 0; 
    while (!isdigit(a[l]))
    {
        l++;
    }
    int c = 1;
    for(int i=l-1; i>=0; i--){

        s += (a[i] - 'A' + 1) * c;
        c *= 26;
    }
    cout << "R" <<  a.substr(l , a.length() - l)<< "C" << s << "\n";
}
string rxcy_to_abc(string a){
    int i=1;
    int r = stoi(a.substr(1, a.find("C") - 1));
    int c = stoi(a.substr(a.find("C") + 1 , a.length() - a.find("C") - 1));
    string m = "";
    while(c > 0){
        if(c % 26 == 0){
            m += "Z";
            c = c/26 -1;
        }
        else{
            m += char((c%26 - 1) + 'A');
            c /= 26;
        }
    }
    reverse(m.begin(), m.end());
    cout << m <<  r << "\n";
    
}
int evaluate_type(string s){
    int i=0, chk = 0;
    while(i<s.length()){
        if(isdigit(s[i])){
            chk = 1;
        }
        else if(chk == 1){
            return 0;
        }
        i++;
    }
    return 1;
}
int main(){
    int n;
    cin >> n;
    while(n --){
        string s;
        cin >> s;
        if(evaluate_type(s)){
            abc_to_rxcy(s);
        }
        else{
            rxcy_to_abc(s);
        }
    }
}