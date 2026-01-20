#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool comp(pair<int,int>p1, pair<int,int>p2){
    return abs(p1.first) + abs(p1.second) < abs(p2.first) + abs(p2.second);
}
int main(){
    int n;
    cin >> n;
    vector<pair<int ,int>>bomb(n);
    for(int i=0; i<n; i++){
        cin >> bomb[i].first >> bomb[i].second;
    }
    sort(bomb.begin(), bomb.end(), comp);
    vector<string>output;
    for(int i=0; i<n; i++){
        int x = bomb[i].first;
        int y = bomb[i].second;
        if (x > 0) output.push_back("1 " + to_string(x) + " R");
        else if (x < 0) output.push_back("1 " + to_string(abs(x)) + " L");
        if (y > 0) output.push_back("1 " + to_string(y) + " U");
        else if (y < 0) output.push_back("1 " + to_string(abs(y)) + " D");
        output.push_back("2");
        if (x > 0) output.push_back("1 " + to_string(x) + " L");
        else if (x < 0) output.push_back("1 " + to_string(abs(x)) + " R");
        if (y > 0) output.push_back("1 " + to_string(y) + " D");
        else if (y < 0) output.push_back("1 " + to_string(abs(y)) + " U");
        output.push_back("3");
    }
    cout << output.size() <<  "\n";
    for(auto s : output){
        cout << s << "\n";
    }

}