#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, ans=1;
        cin >> n >> m;
        vector<int>a;
        while(n--){
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        int b;
        cin >> b;
        a[0] = min(a[0] , b-a[0]);
        for(int i=1; i<a.size(); i++){
            if(a[i-1] > max(a[i] , b-a[i])){
                ans = 0;
                break;
            }
            if(a[i-1] <= min(a[i] , b-a[i])){
                a[i] = min(a[i] , b-a[i]);
            }
            else if (a[i] < a[i-1])
            {
                a[i] = b-a[i];
            }
            
        }
        cout << (ans ? "YES": "NO" )<<"\n";
    }
}
