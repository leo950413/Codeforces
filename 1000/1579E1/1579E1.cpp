#include<iostream>
#include<deque>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        deque<int> d;
        while(n--){
            int temp;
            cin >> temp;
            if(d.empty()){
                d.push_back(temp);
            }
            else{
                if(temp < d[0]){
                    d.push_front(temp);
                }
                else{
                    d.push_back(temp);
                }
            }
        }
        for(auto i : d){
            cout << i << " ";
        }
        cout << "\n";
    }
}