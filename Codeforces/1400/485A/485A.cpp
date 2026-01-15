#include<iostream>
#include<vector>
using namespace std;

int MAX_M = 1e5;

int main(){
    int a, m, k = 0;
    cin >> a >> m;
    for(int i=0; i<MAX_M; i++){
        if(a % m == 0){
            k = 1;
        }
        a = (a + a) % m;
    }
    cout << (k ? "Yes" : "No");
}