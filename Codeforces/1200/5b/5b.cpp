#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    vector<string>v;
    int mx=-1;
    string s;
    while(getline(cin , s)){
        mx = max((int)s.length(), mx);
        v.push_back(s);
    }
    for(int i=0; i<mx+2; i++)cout << "*";
    cout <<"\n";
    int prev = 0;
    for(int i=0; i<v.size(); i++){
        int pad = mx - (int)v[i].length();
        int left = pad / 2;
        int right = pad - left;
        if(pad % 2 == 0){
            cout << "*";
            for(int i=0; i<left; i++)cout << " ";
            cout << v[i];
            for(int i=0; i<right; i++)cout << " "; 
            cout << "*\n";
        }
        else{
            if(prev)swap(left, right);
            cout << "*";
            for(int i=0; i<left; i++)cout << " ";
            cout << v[i];
            for(int i=0; i<right; i++)cout << " "; 
            cout << "*\n";
            prev = !prev;
        }
    }
    for(int i=0; i<mx+2; i++)cout << "*";
}