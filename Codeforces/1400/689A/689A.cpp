#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(10 , 0);
    for(int i=0; i<n; i++){
        char temp;
        cin >> temp;
        v[temp - '0'] = 1;
    }
    if(!v[0]){
        if((v[1] || v[2]|| v[3]) && (v[7] || v[9]) && (v[1] || v[4] || v[7]) && (v[3] || v[6] || v[9])){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    else{
        if(v[1] || v[2] || v[3]){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}