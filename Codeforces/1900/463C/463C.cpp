#include<iostream>
#include<vector>
using namespace std;

long long d1[4005], d2[4005]; 
long long v[2005][2005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
            d1[i - j + n] += v[i][j];
            d2[i + j] += v[i][j];
        }
    }
    long long mx_even = -1, mx_odd = -1;
    pair<int ,int>p1, p2;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            long long curr = d1[i - j + n] + d2[i + j] - v[i][j];
            if((i + j) % 2){
                if(curr > mx_odd){
                    p1.first = i + 1;
                    p1.second = j + 1;
                    mx_odd  = curr;
                }
            }
            else{
                if(curr > mx_even){
                    p2.first = i + 1;
                    p2.second = j + 1;
                    mx_even = curr;
                }
            }
        }
    }
    cout << mx_even + mx_odd << "\n" << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << "\n";
}