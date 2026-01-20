#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m,k;
    int t = 0;
    cin >> n >> m >> k;
    vector<pair<int, int>>temp;
    for(int i=0; i<n; i++){
        if(i % 2){
            for(int j=0; j<m; j++){
                temp.push_back({i + 1 , j + 1});
                if(temp.size() == 2 && t < k - 1){
                    cout << "2 ";
                    for(auto p : temp){
                        cout << p.first << " " << p.second << " ";
                    }
                    cout << "\n";
                    temp.clear();
                    t++;
                }
            }
        }
        else{
            for(int j=m-1; j>=0; j--){
                temp.push_back({i + 1 , j + 1});
                if(temp.size() == 2 && t < k - 1){
                    cout << "2 ";
                    for(auto p : temp){
                        cout << p.first << " " << p.second << " ";
                    }
                    cout << "\n";
                    temp.clear();
                    t++;
                }
            }
        }
    }
    if(!temp.empty()){
        cout << temp.size() << " ";
        for(auto p : temp){
            cout << p.first << " " << p.second << " ";
        }
        cout << "\n";
    }
}