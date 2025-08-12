#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main(){
    vector<vector<int>>hardness(2001);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int h;
        cin >> h;
        hardness[h].push_back(i+1);
    }
    int cnt = 0, ok = 0;
    for(int i=1; i<=2000; i++){
        if(hardness[i].size() == 2){
            cnt+=2;
        }
        if(hardness[i].size() > 2){
            ok=1;
        }
        if(cnt>=3){
            ok = 1;
        }
        if(ok){
            break;
        }
    }
    if(!ok){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(auto &j : hardness){
        for(auto &k : j){
            cout << k << " ";
        }
    }
    cout  << "\n";
    int output_cnt = 1;
    for(int i=1; i<=2000; i++){
        if(hardness[i].size() > 1){
            while (next_permutation(hardness[i].begin(), hardness[i].end()) && output_cnt < 3){
                for(auto &j : hardness){
                    for(auto &k : j){
                        cout << k << " ";
                    }
                }
                cout << "\n";
                output_cnt++;
            }
            if(output_cnt >= 3){
                break;
            }
        }
    }
}