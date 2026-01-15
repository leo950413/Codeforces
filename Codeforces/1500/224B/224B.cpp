#include<iostream>
#include<vector>
#include<set>
using namespace std;


int main(){
    int n,k;
    cin >> n >> k;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int l = 0, r = 0, flag = 0;
    vector<int>uq(n);
    set<int>s;
    for(; r<n; r++){
        s.insert(v[r]);
        if(s.size() == k){
            flag = 1;
            break;
        }
    }
    s.clear();
    if(!flag){
        cout << "-1 -1\n";
        return 0;
    }

    for(int i=r; i>=0; i--){
        s.insert(v[i]);
        uq[i] = s.size();
    }
    // for(int i=0; i<=r; i++){
    //     cout << uq[i] <<" ";
    // }
    cout << "\n";
    for(; l<r; l++){
        if(uq[l] != uq[l+1]){
            break;
        }
    }
    cout << l + 1 << " " << r + 1 << "\n";
}