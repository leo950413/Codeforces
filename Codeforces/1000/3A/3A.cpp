#include<iostream>
#include<vector>
using namespace std;

int main(){
    int x1,y1,x2,y2;
    char t;
    cin >> t >> y1;
    x1 = t - 'a' + 1;
    cin >> t >> y2; 
    x2 = t - 'a' + 1;
    vector<string>ans;
    while(true){
        if(x1==x2&&y1==y2){
            break;
        }
        else if(x1>x2&&y1>y2){
            ans.push_back("LD");
            x1--;y1--;
        }
        else if(x1<x2&&y1<y2){
            ans.push_back("RU");
            x1++;y1++;
        }
        else if(x1>x2&&y1<y2){
            ans.push_back("LU");
            x1--;y1++;
        }
        else if(x1<x2&&y1>y2){
            ans.push_back("RD");
            x1++;y1--;
        }
        else if(x1>x2){
            ans.push_back("L");
            x1--;
        }
        else if(x1<x2){
            ans.push_back("R");
            x1++;
        }
        else if(y1>y2){
            ans.push_back("D");
            y1--;
        }
        else if(y1<y2){
            ans.push_back("U");
            y1++;
        }
    }
    cout<<ans.size()<<"\n";
    for(auto &s:ans) cout<<s<<"\n";
}
