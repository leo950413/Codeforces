#include<vector>
#include<iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int>arr(n) , pre(n);
    long long s = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        s += arr[i];
        pre[i] = s;
    }
    int mm = pre[k - 1] , mm_idx = 0;
    for(int i=1; i + k - 1<n; i++){
        long long interval = pre[k - 1 + i] - pre[i - 1];
        if(interval < mm){
            mm_idx = i;
            mm = interval;
        }
    }
    cout << mm_idx + 1 << "\n";
}