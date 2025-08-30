#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    int n,v;
    cin >> n >> v;
    vector<pair<int , int>>v1 ,v2;
    for(int i=1; i<=n; i++){
        int t,p;
        cin >> t >> p;
        if(t == 1){
            v1.push_back({p, i});
        }
        else{
            v2.push_back({p ,i});
        }
    }
    long long ans = 0;
    sort(v1.begin(), v1.end() , greater<pair<int ,int>>());
    sort(v2.begin(), v2.end() , greater<pair<int ,int>>());

    vector<long long> pre1(v1.size() + 1, 0), pre2(v2.size() + 1, 0);

    for (int i = 0; i < (int)v1.size(); i++) pre1[i + 1] = pre1[i] + v1[i].first;
    for (int i = 0; i < (int)v2.size(); i++) pre2[i + 1] = pre2[i] + v2[i].first;

    long long mx = -1;
    int mx_idx = 0;
    for(int i=0; i<=v1.size(); i++){
        if(i > v)break;
        int pre2_idx = min((v-i)/2 , (int)v2.size());
        // cout<< i<< " "<< pre2_idx << " " << "\n";
        long long curr = pre1[i] + pre2[pre2_idx];
        if(curr > mx){
            mx = max(curr , mx);
            mx_idx = i;
        }
    }
    if(mx == -1){
        cout << "0\n";
        return 0;
    }
    cout << mx << "\n";
    for(int i=0; i<mx_idx; i++){
        cout <<  v1[i].second << " ";
    }
    for(int i=0; i<=min((v-mx_idx)/2 , (int)v2.size())-1; i++){
        cout <<  v2[i].second << " ";
    }
    cout << "\n";
}