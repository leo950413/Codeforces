#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int mx = 110010;
vector<int> prime(mx, 1) , p;
void init_prime(){
    prime[1] = 0;
    for(int i=2; i*i < mx; i++){
        if(prime[i]){
            for(int j=2*i; j < mx; j+=i){
                prime[j] = 0;
            }
        }
            }
    for(int i=2; i< mx; i++){
        if(prime[i])p.push_back(i);
    }
}
int calc(int n){
    return *lower_bound(p.begin(),p.end() , n) - n;
}
int main(){
    init_prime();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n ,vector<int>(m , 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;
            cin >> temp;
            arr[i][j] = calc(temp);
            // cout << arr[i][j] << " ";
        }
    }
    long long mm = 1e9;
    for(int i=0; i<n; i++){
        long long s = 0;
        for(int j=0; j<m; j++){
            s += arr[i][j];
            // cout << arr[i][j] << " ";
        }
        // cout << s << "\n";
        mm = min(s, mm);
    }

    for(int j=0; j<m; j++){
        long long s = 0;
        for(int i=0; i<n; i++){
            s += arr[i][j];
        }
        mm = min(s, mm);
    }
    cout << mm <<"\n";
}