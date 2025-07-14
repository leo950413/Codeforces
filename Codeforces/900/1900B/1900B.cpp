#include<iostream>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        cout << !((b-c)%2); 
        cout << " ";
        cout << !((a-c)%2); 
        cout << " ";
        cout << !((a-b)%2);
        cout << "\n";
    }
}