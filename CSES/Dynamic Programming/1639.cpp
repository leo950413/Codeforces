#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    vector<vector<int>>v(s1.length()+1 , vector<int>(s2.length()+1, 0));
    for(int i=0; i<s1.length()+1; i++){
        v[i][0] = i;
    }
    for(int j=0; j<s2.length()+1; j++){
        v[0][j] = j;
    }
    for(int i=1; i<s1.length()+1; i++){
        for(int j=1; j<s2.length()+1; j++){
            v[i][j] = min({v[i-1][j-1] + !(s1[i-1] == s2[j-1]), v[i-1][j] + 1, v[i][j-1] + 1});
        }
    }
    cout << v[s1.length()][s2.length()] << "\n";
}