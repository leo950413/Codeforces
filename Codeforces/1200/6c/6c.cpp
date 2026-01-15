#include<iostream>
#include<vector>
using namespace std;

int main(){
    int k;
    cin >> k;
    vector<int>v(k);
    for(int i=0; i<k; i++){
        cin >> v[i];
    }
    int l=0,r=k-1,l_sum = 0 , r_sum = 0;
    while(l <= r){
        if(l_sum > r_sum){
            r_sum+=v[r];
            r--;
        }
        else{
            l_sum+=v[l];
            l++;
        }
    }
    cout << l << " " <<  k-l <<"\n";
}