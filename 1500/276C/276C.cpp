#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int>vec(n,0), freq(n+1, 0);
    vector<pair<int , int>> query;
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    for(int i=0; i<q; i++){
        int l,r;
        cin >> l >> r;
        freq[l - 1] ++;
        freq[r]--;
    }
    for(int i=1; i< n; i++){
        freq[i] +=  freq[i-1];
    }
    sort(vec.begin(), vec.end(), greater<int>());
    sort(freq.begin(), freq.end(), greater<int>());
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += 1LL * vec[i] * freq[i];
    }

    cout << sum << "\n";
}

// 例子來看更清楚
// 假設 n = 5，有一筆區間查詢 l = 2, r = 4，也就是區間 [2, 3, 4]

// 初始 freq：

// perl
// Copy
// Edit
// 0 0 0 0 0 0  // freq[0..5]，多一格差分用
// 執行：

// cpp
// Copy
// Edit
// freq[l - 1]++; // freq[1]++
// freq[r]--;     // freq[4]--
// 現在 freq：

// Copy
// Edit
// 0 1 0 0 -1 0
// 接著做 prefix sum：

// Copy
// Edit
// 0 1 1 1 0
// 這就代表：

// index 1~3（也就是原本的 [2, 3, 4]）都被加了 1 次