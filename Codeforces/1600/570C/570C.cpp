#include<vector>
#include<iostream>
#include<string>

using namespace std;
int main(){
    int n , m;
    string s;
    cin >> n >> m;
    cin >> s;
    vector<int>v(n+2);
    v[0] = 1;
    v[n+1] = 1;
    int dot_total = 0 , curr = 0;
    for(int i=1; i<=n; i++){
        if(s[i-1] == '.'){
            v[i] = 0;
            curr++;
        }
        else{
            v[i] = 1;
            if(curr >= 2){
                dot_total += curr-1;
            }
            curr=0;
        }
    }
    if(curr >= 2){
        dot_total += curr-1;
    }
    for (int i = 0; i < m; i++) {
        int x;
        char c;
        cin >> x >> c;

        int left  = v[x - 1];
        int mid   = v[x];
        int right = v[x + 1];

        if (c == '.') {
            if (left == 0 && mid == 1 && right == 0) { // was filled, now becomes gap between dots
                dot_total += 2;
            } 
            else if ((left == 0 && mid == 1 && right == 1) || (left == 1 && mid == 1 && right == 0)) {
                dot_total += 1;
            }
            v[x] = 0;
        } 
        else { // c != '.'
            if (left == 0 && mid == 0 && right == 0) { // was big gap, now split
                dot_total -= 2;
            } 
            else if ((left == 0 && mid == 0 && right == 1) ||
                     (left == 1 && mid == 0 && right == 0)) {
                dot_total -= 1;
            }
            v[x] = 1;
        }

        cout << dot_total << "\n";
    }
}