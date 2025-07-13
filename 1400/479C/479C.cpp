#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

// int cmp(pair<int , int>l , pair<int,int> r){
//     return l.first > r.first;
// }
int main(){
    int n;
    cin >> n;
    vector<pair<int , int>> vec;
    while(n--){
        int a,b;
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }
    sort(vec.begin() , vec.end());
    int ans = -1;
    for(int i=0; i<vec.size(); i++){
        if(ans <= vec[i].second){
            ans = vec[i].second;
        }
        else{
            ans = vec[i].first;
        }
    }
    cout << ans;
}