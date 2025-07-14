#include<vector>
#include<iostream>

using namespace std;

int main(){
    int n , max_id , maxm=-10000 , min_id , minm=10000;
    vector<int>arr;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        arr.push_back(t);
        if(t > maxm){
            max_id = arr.size() - 1;
            maxm = t;
        }
        if(t <= minm){
            min_id = arr.size() - 1;
            minm = t;
        }
    }
    if(min_id < max_id){
        cout << max_id + arr.size() - min_id - 2 << "\n";
    }
    else{
        cout << max_id + arr.size() - min_id - 1<< "\n";
    }

    

}