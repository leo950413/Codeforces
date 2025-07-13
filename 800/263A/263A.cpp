#include<iostream>

using namespace std;

int main(){
    int i,j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            int t;
            cin >> t;
            if(t){
                cout <<abs(2-i) + abs(2-j) << "\n";
                return 0;

            }
        }
    }
    // cout << (2-i) <<  ' '  <<  (2-j) << "\n";
}