#include<iostream>
using namespace std;

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1-x2 != 0){
        double s = (double)(y1 - y2) / (x1 - x2);
        if(!(s == 1 || s== 0 || s==-1)){
            cout << -1 << "\n";
            return 0;
        }
    }
    if(x1!=x2 && y1 != y2){
        cout << x1 << " " << y2  << " " << x2 << " " << y1 <<  "\n";
    }
    else if(y1 == y2){
        int d = abs(x1-x2);
        cout << x1 << " " << y1+d << " " << x2 << " " << y2 + d << "\n";
    }
    else{
        int d = abs(y1-y2);
        cout << x1+d << " " << y1 << " " << x2+d << " " << y2 << "\n";
    }
}