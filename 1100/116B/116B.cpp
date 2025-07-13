#include<iostream>
#include<vector>

using namespace std;

int in_bound(int n, int m, int i , int j){
    if(i<n && i>=0){
        if(j<m && j>=0){
            return true;
        }
    }
    return false;
}
int main(){
    int d[4][2] = {
        { 1,  0}, 
        {-1,  0},   
        { 0,  1},  
        { 0, -1}    
    };
    int n,m , ans = 0;
    cin >> n >> m;
    vector<vector<char>>arr(n , vector<char>(m , 0));
    vector<vector<int>>side(n , vector<int>(m , 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin >> c;
            arr[i][j] = c;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 'P'){
                for(int k=0; k<4; k++){
                    if(in_bound(n , m , i+d[k][0] , j+d[k][1])){
                        if (arr[i+d[k][0]][j+d[k][1]] == 'W'){
                            ans++;
                            arr[i+d[k][0]][j+d[k][1]] = '.';
                        }   
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
