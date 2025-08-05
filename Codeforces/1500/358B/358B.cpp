#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string str1 = "<3";
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        str1 += temp + "<3";
    }
    string str2;
    cin >> str2;
    int j = 0;
    for(int i=0; i<str2.length(); i++){
        if(str1[j] == str2[i]){
            j++;
        }
        if(j == str1.length()){
            cout << "yes\n";
            return 0;
        }
    }
    cout << "no\n";
}