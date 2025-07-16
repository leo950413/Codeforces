#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;
int main(){
    int n,x;
    cin >> n >> x;
    unordered_map<int ,int>m;
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        if(m.find(a) == m.end()){
            m.insert({x-a, i});
        }
        else{
            cout << m[a] << " " << i << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}