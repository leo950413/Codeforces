#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    int l = -2*1e9, r = 2*1e9; // include both end
    map<string ,string>m ={{">=" , "<" }, {"<=" , ">"}, {">" , "<="} , {"<" , ">="}};
    int n;
    cin >> n;
    while(n--){
        string op ,ans;
        int x;
        cin >> op >> x >> ans;
        if(ans == "N"){
            op = m[op];
        }
        if(op == "<"){
            if(x-1 > r)continue;
            r = x - 1;
        }
        else if (op == ">"){
            if(x + 1 < l)continue;
            l = x + 1;
        }
        else if (op == ">="){
            if(x  < l)continue;
            l = x;
        }
        else{
            if(x > r)continue;
            r = x;
        }
    }
    if(l > r) cout << "Impossible\n";
    else cout << l << "\n";
}