#include<iostream>
#include<vector>

using namespace std;
void solve(){
    int n;
    cin>>n;

    vector<int> b(n);
    for(int i=0;i<n;i++)cin>>b[i];

    vector<vector<int>>pos(n+1);
    for(int i=0;i<n;i++) pos[b[i]].push_back(i);

    vector<int> a(n,-1);

    int label=1;
    bool ok=true;
    for(int k=1;k<=n;k++){

        if(pos[k].empty()) continue;

        if(pos[k].size()%k!=0){
            ok=false;
            break;
        }
        for(int i=0;i<pos[k].size();i+=k){
            for(int j=0;j<k;j++){
                a[pos[k][i+j]]=label;
            }
            label++;
        }
    }
    if(!ok) cout << -1 << "\n";
    else{
        for(int i=0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
