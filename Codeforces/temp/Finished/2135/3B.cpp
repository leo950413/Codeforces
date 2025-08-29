#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    int n,v;
    cin >> n >> v;
    vector<int>v1 ,v2;
    for(int i=0; i<n; i++){
        int t,p;
        cin >> t >> p;
        if(t == 1){
            v1.push_back(p);
        }
        else{
            v2.push_back(p);
        }
    }
    long long ans = 0;
    sort(v1.begin(), v1.end() , greater<int>());
    sort(v2.begin(), v2.end() , greater<int>());
    for(int i=0; i+2<=v; i+=2){
        if(v)
    }
}