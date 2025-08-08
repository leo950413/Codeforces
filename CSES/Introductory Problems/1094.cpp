#include<iostream>

using namespace std;

int main(){
    int n;
    long long s = 0;
    cin >> n;
    int prev;
    cin >> prev;
    for(int i=1; i<n; i++){
        int curr;
        cin >> curr;
        s += max(0 , prev-curr);
        prev = max(curr, prev);
    }
    cout << s<< "\n";
}