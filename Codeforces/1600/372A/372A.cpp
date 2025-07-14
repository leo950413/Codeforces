#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    int combine = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    int j = (n + 1) / 2;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) continue;
        while (j < n && a[j] < 2 * a[i]) ++j;
        if (j < n) {
            a[i] = a[j] = 0;
            ++combine;
            ++j;
        }
    }

    cout << n - combine << "\n";
}