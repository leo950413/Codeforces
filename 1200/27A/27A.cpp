#include<iostream>
using namespace std;

int main(){
    int n;
    int arr[3001]={0};
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        arr[t-1] += 1;
    }
    for(int i=0; i<3001; i++){
        if(arr[i] == 0){
            cout << i+1 << "\n";
            break;
        }
    }
}