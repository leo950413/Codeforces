#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    vector<int>v;
    int n , x;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    if(find(v.begin() , v.end() , x) == v.end()){
        v.push_back(x);
    }
    sort(v.begin() , v.end());
    while(v[(v.size() + 1)/2 - 1] != x){
        if(v[(v.size() + 1)/2 - 1] > x){
            v.insert(v.begin() , 1);
        }
        else{
            v.insert(v.end() , 100000);
        }
        // for(auto  i:v){
        //     cout << i<< " ";
        // }
    }
    cout << v.size() - n;
}