#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,x,ans=0;
    cin>>n>>x;
    vector<int>vec(n);
    for(size_t i=0; i<n; i++){
        cin >> vec[i];
    }
    sort(vec.begin() , vec.end());
    int i=0, j=vec.size() - 1;
    while (i<=j){
        if(vec[i] + vec[j] > x){
            ans += 1;
            j--;
        }
        else{
            ans+=1;
            i++;
            j--;
        }
    }
    cout << ans << "\n";
}