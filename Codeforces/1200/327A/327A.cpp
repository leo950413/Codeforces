#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n , ans =0 , sum = 0 , num_of_1 = 0;
    cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i])num_of_1 ++;
    }
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            sum++;
        }
        else{
            sum--;
        }
        ans = max(sum , ans);
        if(sum < 0){
            sum = 0;
        }
    }
    if(num_of_1 == n){
        cout << n-1 << "\n";
    }
    else{
        cout << num_of_1 + ans << "\n";
    }
}