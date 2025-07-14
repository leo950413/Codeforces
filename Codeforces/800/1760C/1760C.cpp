#include<iostream>
#include<vector>

using namespace std;

void sol(){
    vector<int>arr;
    int n;
    cin >> n;
    int t1=-10000, t2=-10000;
    while(n--){
        int temp;
        cin >> temp;
        if(temp > t1){
            swap(t1 , t2);
            t1 = temp;
        }
        else if(temp > t2){
            t2 = temp;
        }
        arr.push_back(temp);
    }
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==t1)cout << t1-t2 << " ";
        else{cout << arr[i] - t1 << " ";}
    }
    cout << "\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        sol();
    }
}