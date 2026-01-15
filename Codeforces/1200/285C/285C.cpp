#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int t;
    vector<int>v;
    cin >> t;
    long long s = 0;
    while(t--){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        s += abs(v[i] - i - 1);
    }
    cout << s << "\n";
}