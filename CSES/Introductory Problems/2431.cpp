#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main(){
    int q;
    cin >> q;

    while(q--){
        long long t;
        cin >> t;

        long long digit = 1;
        long long count = 9;
        long long start = 1;

        while (t > digit * count) {
            t -= digit * count;
            digit++;
            count *= 10;
            start *= 10;
        }

        long long num = start + (t - 1) / digit;

        string s = to_string(num);
        cout << s[(t - 1) % digit] << "\n";
    }

    return 0;
}
