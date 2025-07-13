#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    vector<int>dancer(a+1 , 0);
    for(int i=0; i<b; i++){
        vector<int>d(3);
        vector<int>color({1, 2 ,3});
        cin >> d[0] >> d[1] >> d[2];
        for(int j=0; j<3; j++){
            if(dancer[d[j]] != 0){
                auto it = find(color.begin(), color.end(), dancer[d[j]]);
                    if (it != color.end()) {
                        color.erase(it);
                }
                d[j] = -1;
            }
        }
        for(int j=0; j<3; j++){
            if(d[j] == -1)continue;
            dancer[d[j]] = color[0];
            color.erase(color.begin());
        }
    }
    for(int i=1; i<=a; i++){
        cout << dancer[i] << " ";
    }
}