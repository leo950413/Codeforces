#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<int>a){
    for(auto i : a){
        cout << i << " ";
    }
    cout << "\n";
}
void solution(){
    
    int n,k;
    cin >> n >> k;
    vector<int>a;

    while (n--)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);

    }
    a.push_back(200000000);
    sort(a.begin(), a.end());
    int ans = 0;
    int j=0;
    // print(a);
    for(int i=0; i<a.size(); i++){
        j = max(i , j);
        while(a[j+1] - a[i] <k && j<a.size()&&a[j+1] - a[j] <= 1){
                j++;
    
        }

        // cout << i << " " << j << "\n";
        ans = max(ans ,j-i+1); // [i , j] include both endpoint.
    }
    cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solution();
    }
}