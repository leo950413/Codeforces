#include<iostream>
#include <climits>

using namespace std;

int main(){
    int n;
    cin>>n;
    int min_num = INT_MAX , num_of_min = 0 , id = 0;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        if(t < min_num){
            if(min_num != t){
                num_of_min = 0;
            }
            min_num = t;
            num_of_min += 1;
            id = i;
        }
        else if (t==min_num)
        {
            num_of_min ++;
        }
        
    }
    if(num_of_min > 1){
        cout << "Still Rozdil" << "\n";
    }
    else{
        cout << id+1 << "\n";
    }
}